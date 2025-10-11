class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) swap(maxProd, minProd);
            maxProd = max(nums[i], nums[i] * maxProd);
            minProd = min(nums[i], nums[i] * minProd);
            ans = max(ans, maxProd);
        }
        return ans;
    }
};