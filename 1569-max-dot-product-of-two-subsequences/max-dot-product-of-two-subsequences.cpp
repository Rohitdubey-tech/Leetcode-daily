class Solution {
public:
    
    int dp[501][501];

    int maxProduct(vector<int>& nums1, vector<int>& nums2, int i1, int i2){
        if(i1 == nums1.size() || i2 == nums2.size()) return -1e9;
        if(dp[i1][i2] != -1e9) return dp[i1][i2];

        int nt = maxProduct(nums1, nums2, i1+1, i2+1);
        int t  = nums1[i1] * nums2[i2] + maxProduct(nums1, nums2, i1+1, i2+1);
        int n1 = maxProduct(nums1, nums2, i1+1, i2);
        int n2 = maxProduct(nums1, nums2, i1, i2+1);

        return dp[i1][i2] = max({nums1[i1] * nums2[i2],t, nt, n1, n2});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < 501; i++)
            for(int j = 0; j < 501; j++)
                dp[i][j] = -1e9;

        return maxProduct(nums1, nums2, 0, 0);
    }
};