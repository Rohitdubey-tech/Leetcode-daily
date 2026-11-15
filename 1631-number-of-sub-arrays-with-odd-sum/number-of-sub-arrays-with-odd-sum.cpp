class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        long long prefix_sum = 0;
        long long odd_count = 0;

        for (int i : arr) {
            prefix_sum += i;
            odd_count += prefix_sum % 2;
        }

        odd_count += ((long long)arr.size() - odd_count) * odd_count;

        return odd_count % MOD;
    }
};