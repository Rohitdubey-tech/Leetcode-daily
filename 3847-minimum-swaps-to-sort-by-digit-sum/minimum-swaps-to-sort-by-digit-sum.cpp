using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;

template <u64 value>
using UintForValue = std::conditional_t < value < (1 << 8),
      u8,
      std::conditional_t <
          value<
              (1 << 16),
              u16,
              std::conditional_t<value<(1UL << 32), u32, u64>>>;

struct RadixSortIndicesByStorage
{
    template <std::unsigned_integral I, u32 capacity>
    inline static I scratch[capacity];

    alignas(u32) inline static u8 counts[sizeof(u32) << 16];
};

template <
    u8 bits_per_pass,
    u32 num_passes = 0xFFFFFFFF,
    u32 capacity = 100'001,
    std::unsigned_integral I,
    typename Proj>
[[gnu::no_sanitize_address, gnu::flatten]] void
radix_sort_indices_by(I* indices, u32 n, Proj proj) noexcept
{
    using Key = std::remove_cvref_t<std::invoke_result_t<Proj&, I>>;
    using Count = UintForValue<capacity>;
    static_assert(std::unsigned_integral<Key>);
    static_assert(bits_per_pass > 0 && bits_per_pass <= 16);

    constexpr u32 radix = 1u << bits_per_pass;
    constexpr Key mask = radix - 1;
    constexpr u32 max_passes =
        (sizeof(Key) * 8 + bits_per_pass - 1) / bits_per_pass;
    constexpr u32 passes = num_passes == 0xFFFFFFFF ? max_passes : num_passes;
    static_assert(passes <= max_passes);

    auto* counts = reinterpret_cast<Count*>(RadixSortIndicesByStorage::counts);
    assert(n <= capacity);  // NOLINT
    I* src = indices;
    I* dst = RadixSortIndicesByStorage::scratch<I, capacity>;

    for (u32 pass = 0; pass < passes; ++pass)
    {
        std::memset(counts, 0, radix * sizeof(Count));
        const u32 shift = pass * bits_per_pass;
        for (u32 pos = 0; pos < n; ++pos)
        {
            ++counts[(proj(src[pos]) >> shift) & mask];
        }

        for (u32 i = 1; i < radix; ++i)
        {
            counts[i] += counts[i - 1];
        }
        for (u32 pos = n; pos--;)
        {
            const I index = src[pos];
            const Key digit = (proj(index) >> shift) & mask;
            dst[--counts[digit]] = index;
        }
        std::swap(src, dst);
    }
    if (passes % 2 && n)
    {
        std::memcpy(indices, src, n * sizeof(I));
    }
}

template <
    u32 key_bits,
    u32 capacity = 100'001,
    std::unsigned_integral I,
    typename Init,
    typename Proj>
[[nodiscard, gnu::no_sanitize_address, gnu::flatten]] I*
adaptive_sort_indices_by(I* indices, u32 n, Init init, Proj proj) noexcept
{
    using Key = std::remove_cvref_t<std::invoke_result_t<Proj&, I>>;
    static_assert(std::unsigned_integral<Key>);
    static_assert(key_bits > 0 && key_bits <= sizeof(Key) * 8);
    assert(n <= capacity);  // NOLINT

    // init prepares each index's projection state and returns its key once.
    auto sort =
        [&]<u32 bits> [[gnu::no_sanitize_address, gnu::flatten]] () -> I*
    {
        using Count = UintForValue<capacity>;
        constexpr u32 radix = 1u << bits;
        constexpr u32 passes = bits ? (key_bits + bits - 1) / bits : 0;
        auto* counts =
            reinterpret_cast<Count*>(RadixSortIndicesByStorage::counts);
        if constexpr (bits)
        {
            constexpr u32 last_radix = 1u << (key_bits - (passes - 1) * bits);
            constexpr u32 total_counts = (passes - 1) * radix + last_radix;
            static_assert(
                total_counts * sizeof(Count) <=
                sizeof(RadixSortIndicesByStorage::counts));
            std::memset(counts, 0, total_counts * sizeof(Count));
        }
        for (u32 i = 0; i != n; ++i)
        {
            const I index = static_cast<I>(i);
            indices[i] = index;
            const Key key = init(index);
            if constexpr (bits)
            {
                for (u32 pass = 0; pass < passes; ++pass)
                {
                    ++counts
                        [pass * radix + ((key >> (pass * bits)) & (radix - 1))];
                }
            }
        }

        if constexpr (!bits)
        {
            std::ranges::sort(indices, indices + n, std::less{}, proj);
            return indices;
        }
        else
        {
            constexpr u32 last_radix = 1u << (key_bits - (passes - 1) * bits);
            I* src = indices;
            I* dst = RadixSortIndicesByStorage::scratch<I, capacity>;
            auto* all_counts = counts;
            for (u32 pass = 0; pass < passes; ++pass)
            {
                counts = all_counts + pass * radix;
                const u32 shift = pass * bits;
                for (u32 i = 1; i < (pass + 1 == passes ? last_radix : radix);
                     ++i)
                {
                    counts[i] += counts[i - 1];
                }
                for (u32 pos = n; pos--;)
                {
                    const I index = src[pos];
                    const Key digit = (proj(index) >> shift) & (radix - 1);
                    dst[--counts[digit]] = index;
                }
                std::swap(src, dst);
            }
            return src;
        }
    };

    if (n < 256) return sort.template operator()<0>();
    if (n < 1280) return sort.template operator()<std::min(8u, key_bits)>();
    if (n < 8192) return sort.template operator()<std::min(10u, key_bits)>();
    return sort.template operator()<std::min(13u, key_bits)>();
}
#ifndef LC_LOCAL_BUILD
auto init = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 'c';
}();
#endif

class Solution
{
public:
    inline static constexpr auto kDigitSums = []
    {
        std::array<u8, 100'000> table{};
        auto* data = table.data();
        for (u32 i = 1; i != table.size(); ++i)
        {
            data[i] = (data[i / 10] + i % 10) & 0xFF;
        }
        return table;
    }();

    [[nodiscard,
      gnu::target("bmi2,avx2"),
      gnu::always_inline,
      gnu::no_sanitize_address,
      gnu::flatten]] static u8
    digitSum(u32 x) noexcept
    {
        return static_cast<u8>(
            kDigitSums[x % 100'000] + kDigitSums[x / 100'000]);
    }

    inline static u8 sums[100'000];
    alignas(u32) inline static u8 sorted_storage[sizeof(u32) * 100'000];

    template <u32 kMaxN>
    [[gnu::target("bmi2,avx2"), gnu::no_sanitize_address, gnu::flatten]]
    static u32 impl(const std::vector<int>& nums) noexcept
    {
        using Index = UintForValue<kMaxN>;
        static_assert(sizeof(Index) * kMaxN <= sizeof(sorted_storage));
        auto* sorted = reinterpret_cast<Index*>(sorted_storage);
        const auto* a = reinterpret_cast<const u32*>(nums.data());
        const u32 n = static_cast<u32>(nums.size());

        auto init = [a]
            [[gnu::target("bmi2,avx2"),
              gnu::no_sanitize_address,
              gnu::flatten]] (Index i) -> u64
        {
            sums[i] = digitSum(a[i]);
            return (u64{sums[i]} << 30) | a[i];
        };

        auto proj = [a] [[gnu::always_inline, gnu::no_sanitize_address]] (
                        Index i) -> u64
        {
            return (u64{sums[i]} << 30) | a[i];
        };

        sorted = adaptive_sort_indices_by<37, kMaxN>(sorted, n, init, proj);

        u32 num_swaps = 0;

        for (u32 i = 0; i != n; ++i)
        {
            if (sorted[i] == i) continue;
            u32 j = i;
            do
            {
                const u32 next = sorted[j];
                sorted[j] = static_cast<Index>(j);
                j = next;
                ++num_swaps;
            } while (j != i);
            --num_swaps;
        }

        return num_swaps;
    }

    [[gnu::target("bmi2,avx2"), gnu::no_sanitize_address, gnu::flatten]]
    u32 minSwaps(const std::vector<int>& nums) const noexcept
    {
        if (nums.size() <= 65'535) return impl<65'535>(nums);
        return impl<100'000>(nums);
    }
};