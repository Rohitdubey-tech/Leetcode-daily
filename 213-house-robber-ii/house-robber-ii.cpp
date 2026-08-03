class Solution {
public:
    int solve(vector<int>& nums, int start, int end){
        vector<int>dp(end - start + 1);
        dp[0] = nums[start];
        for(int i=start+1; i<=end; i++){
            int index = i - start;
            int pick = nums[i];
            if(index > 1){
                pick += dp[index - 2];
            }
            int notPick = dp[index-1];
            dp[index]=max(pick, notPick);

        }
        return dp[end-start];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
             return nums[0];
        }
        int excludeLast = solve(nums, 0, n-2);
        int excludeFirst = solve(nums, 1, n-1);
        return max(excludeFirst, excludeLast);
    }
};