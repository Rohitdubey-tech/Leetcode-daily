class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low1= nums[0];
        int low2 = nums[1];
        int high1=nums[n-1];
        int high2 = nums[n-2];
        return (high1 * high2) - (low1*low2);
    }
};