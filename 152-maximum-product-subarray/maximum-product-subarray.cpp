class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax = nums[0];
        int currMin = nums[0];
        int ans = nums[0];
        for(int i=1; i<nums.size(); i++){
            int temp = currMax;
            currMax = max({nums[i], nums[i]*currMax, nums[i]* currMin});
            currMin = min({nums[i], nums[i]*currMin, nums[i]*temp});
            ans = max(ans, currMax);
        }
        return ans;
    }
};