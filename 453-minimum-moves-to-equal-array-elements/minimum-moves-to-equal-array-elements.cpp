class Solution {
public:
    int minMoves(std::vector<int>& nums) {
        long long sum = 0;
        int min_val = nums[0];
        for (int x : nums) {
            sum += x;
            if (x < min_val) min_val = x;
        }
        return static_cast<int>(sum - 1LL * nums.size() * min_val);
    }
};