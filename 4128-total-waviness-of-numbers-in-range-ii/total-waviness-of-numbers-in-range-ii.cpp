class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[17][2][3][10][10];
    bool vis[17][2][3][10][10];

    Node dfs(int pos, int started, int lenState, int a, int b, bool tight) {

        if (pos == (int)s.size()) {
            return {1, 0};
        }

        if (!tight && vis[pos][started][lenState][a][b]) {
            return dp[pos][started][lenState][a][b];
        }

        int limit = tight ? (s[pos] - '0') : 9;

        Node res = {0, 0};

        for (int d = 0; d <= limit; d++) {
            bool ntight = tight && (d == limit);

            if (!started && d == 0) {
                Node nxt = dfs(pos + 1, 0, 0, 0, 0, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else if (!started) {
                Node nxt = dfs(pos + 1, 1, 1, 0, d, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else if (lenState == 1) {
                Node nxt = dfs(pos + 1, 1, 2, b, d, ntight);
                res.cnt += nxt.cnt;
                res.wav += nxt.wav;
            } else {
                int add = ((b > a && b > d) || (b < a && b < d)) ? 1 : 0;

                Node nxt = dfs(pos + 1, 1, 2, b, d, ntight);

                res.cnt += nxt.cnt;
                res.wav += nxt.wav + 1LL * add * nxt.cnt;
            }
        }

        if (!tight) {
            vis[pos][started][lenState][a][b] = true;
            dp[pos][started][lenState][a][b] = res;
        }

        return res;
    }

    long long solve(long long N) {
        if (N < 0)
            return 0;

        s = to_string(N);
        memset(vis, 0, sizeof(vis));

        return dfs(0, 0, 0, 0, 0, true).wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};