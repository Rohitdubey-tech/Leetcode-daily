class Solution {
public:
    int MOD = 1E9 + 7;

    int dfs(int node,
            vector<vector<int>>& adj,
            vector<bool>& visited) {

        visited[node] = true;

        int maxDepth = 0;

        for (auto& nei : adj[node]) {

            if (!visited[nei]) {

                int depth =
                    1 + dfs(nei, adj, visited);

                maxDepth = max(maxDepth, depth);
            }
        }

        return maxDepth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;

        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, false);

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxHeight = dfs(1, adj, visited);

        vector<vector<long long>> dp(
            maxHeight + 1,
            vector<long long>(2, 0)
        );
        dp[0][0] = 1;

        for (int i = 1; i <= maxHeight; i++) {

            dp[i][0] =
                (dp[i - 1][0] + dp[i - 1][1]) % MOD;

            dp[i][1] =
                (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        }

        return dp[maxHeight][1] % MOD;
    }
};