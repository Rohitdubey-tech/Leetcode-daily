class Solution {
public:
    const int MOD = 1e9+7;
    int dp[201][201][2];

    int solve(int z, int o, int last, int zero, int one, int limit) {
        if (z == zero && o == one) return 1;
        
        if (dp[z][o][last] != -1)
            return dp[z][o][last];

        long long res = 0;

        if (last == 0) { 
            for (int k = 1; k <= limit && o + k <= one; ++k)
                res = (res + solve(z, o + k, 1, zero, one, limit)) % MOD;
        } 
        else { 
            for (int k = 1; k <= limit && z + k <= zero; ++k)
                res = (res + solve(z + k, o, 0, zero, one, limit)) % MOD;
        }

        return dp[z][o][last] = (int)res;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp, -1, sizeof(dp));
        long long res = 0;

        for (int k = 1; k <= limit && k <= zero; ++k)
            res = (res + solve(k, 0, 0, zero, one, limit)) % MOD;

        for (int k = 1; k <= limit && k <= one; ++k)
            res = (res + solve(0, k, 1, zero, one, limit)) % MOD;

        return (int)res;
    }
};