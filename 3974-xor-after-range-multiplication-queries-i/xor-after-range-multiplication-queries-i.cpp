class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        
        for (int i=0;i<queries.size();i++) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], v = queries[i][3];
            
            for (int idx = l; idx <= r; idx += k) {
                nums[idx] = (1LL * nums[idx] * v) % MOD;
            }
        }
        
        int ans = 0;
        for (int i=0;i<nums.size();i++) {
            ans ^= nums[i];
        }
        
        return ans;
    }
};