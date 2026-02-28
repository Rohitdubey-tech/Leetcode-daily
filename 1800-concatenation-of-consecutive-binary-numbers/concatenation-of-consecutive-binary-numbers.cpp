class Solution {
  constexpr static uint64_t M = 1e9 + 7;
  constexpr static uint64_t one = 1;

  inline uint64_t mod(uint64_t x) { return x % M; }

  inline uint64_t fastPow(uint64_t x, uint64_t k) {
    uint64_t res = 1;
    while (k > 0) {
      if (k & 1) res = mod(res * x);
      k >>= 1;
      x = mod(x * x);
    }
    return res;
  }

 public:
  int concatenatedBinary(const int n) {
    const uint64_t un = static_cast<uint64_t>(n);
    uint64_t res = 0;

    for (int w = 1; w <= 31; ++w) {
      uint64_t xReal = one << (w - 1);
      uint64_t yReal = min((one << w) - 1, un);

      uint64_t k = (yReal - xReal + 1);
      uint64_t x = mod(xReal);
      uint64_t y = mod(yReal);
      uint64_t r = fastPow(2, w);         // 2^w
      uint64_t rk = fastPow(r, k);        // r^k
      uint64_t s = mod(r + M - 1);        // r-1
      uint64_t sInv = fastPow(s, M - 2);  // 1/(r-1)
      uint64_t sInv2 = mod(sInv * sInv);  // 1/(r-1)^2

      uint64_t term0 = mod(res * rk);                    // shift current result
      uint64_t term1 = mod(mod(x * rk + M - y) * sInv);  // (xr^k - y) / (r-1)
      uint64_t term2 = mod(mod(rk + M - r) * sInv2);     // (r^k - r) / (r-1)^2
      res = mod(term0 + term1 + term2);

      if (y == un) break;
    }

    return res;
  }
};