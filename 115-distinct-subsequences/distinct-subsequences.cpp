class Solution {
public:
    
    int mod = 1e9+7;
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][m] = 1;
        }
        for(int ind1 = n-1;ind1>=0;ind1--){
            for(int ind2= m-1;ind2>=0;ind2--){
                int pick=0, notPick=0;
                if(s[ind1]==t[ind2])
                   pick = dp[ind1+1][ind2+1];

                notPick = dp[ind1+1][ind2];
                dp[ind1][ind2] = (pick + notPick)%mod;
            }
        }
        return dp[0][0];
    }
};