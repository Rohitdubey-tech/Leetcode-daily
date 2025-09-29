class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        if (n < 3) return 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 3; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                int best = INT_MAX;

                for (int k = i + 1; k <= j - 1; ++k) {
                    int cost = dp[i][k] + dp[k][j] + values[i] * values[k] * values[j];
                    if (cost < best) best = cost;
                }
                dp[i][j] = best;
            }
        }
        return dp[0][n-1];
    }
};
