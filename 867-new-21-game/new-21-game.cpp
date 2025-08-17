class Solution {
    public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;
        vector<double> dp(n + 1, 0.0);
        for (int x = k; x <= n; x++) {
            dp[x] = 1.0;
        }
        double W = n - k + 1;
        for (int x = k - 1; x >= 0; x--) {
            dp[x] = W / maxPts;
            W += dp[x];
            if (x + maxPts <= n) {
                W -= dp[x + maxPts];
            }
        }
        return dp[0];
    }
};