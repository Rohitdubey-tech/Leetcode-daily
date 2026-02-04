class Solution {
public:
    const int mod = 1e9+7;
    int dp[1001][2][1000];
    int cal(int i, int state, int n, int k){
        if(k==0) return 1;
        if(i==n) return 0;
        int &ans = dp[i][state][k];
        if(ans != -1) return ans;
        if(state == 1){
            ans = cal(i,0,n,k-1);
            ans = (ans + cal(i+1, 1, n, k))%mod;
    }
    else{
        ans = cal(i+1,1,n,k);
        ans = (ans + cal(i+1,0,n,k)) % mod;
    }
    return ans;
}
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return cal(0,0,n,k);
    }
};