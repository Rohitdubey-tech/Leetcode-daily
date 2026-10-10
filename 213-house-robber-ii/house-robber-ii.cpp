class Solution {
public:
    int solve(int i, vector<int>& nums, int end, vector<int>& dp){
        if(i>end){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int rob = nums[i] + solve(i+2, nums, end, dp);
        int skip = solve(i+1, nums, end, dp);
        return dp[i] = max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp1(n, -1);
        vector<int>dp2(n, -1);
        if(n==1) return nums[0];
        int case1 = solve(0, nums, n-2, dp1);
        int case2 = solve(1, nums, n-1, dp2);
        return max(case1, case2);
    }
};