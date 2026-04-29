class Solution {
public:
    long long maximumScore(vector<vector<int>>& grid) {
        const int n{static_cast<int>(grid.size())};
        static constexpr long long MN{static_cast<long long>(-1e18)};
        static long long cur[101][2];
        fill(&cur[0][0], &cur[100][1], MN);
        for (int j{0}; j <= n; ++j) cur[j][0] = 0;
        for (int i{1}; i < n; ++i) {
            static long long nxt[101][2];
            fill(&nxt[0][0], &nxt[100][1], MN);
            for (int j{0}; j <= n; ++j) {
                if (max(cur[j][0], cur[j][1]) > MN) nxt[j][0] = max(nxt[j][0], max(cur[j][0], cur[j][1]));
                long long down{0};
                for (int k{j + 1}; k <= n; ++k) {
                    down += grid[k - 1][i];
                    long long best{max(cur[k][0], cur[k][1])};
                    if (best > MN) {
                        nxt[j][1] = max(nxt[j][1], best + down);
                        nxt[j][0] = max(nxt[j][0], best);
                    }
                }
                long long up{0};
                for (int k{j - 1}; k >= 0; --k) {
                    up += grid[k][i - 1];
                    if (cur[k][0] > MN) nxt[j][0] = max(nxt[j][0], cur[k][0] + up);
                    if (cur[k][1] > MN) nxt[j][0] = max(nxt[j][0], cur[k][1]);
                }
            }
            memcpy(cur, nxt, sizeof(cur));
        }
        long long res{0};
        for (int j{0}; j <= n; ++j) res = max({res, cur[j][0], cur[j][1]});
        return res;
    }
};