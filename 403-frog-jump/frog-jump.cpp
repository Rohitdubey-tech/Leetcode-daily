
class Solution {
public:
    bool solve(int i, int lastJump,
               vector<int>& stones,
               unordered_map<int, int>& pos,
               vector<vector<int>>& dp) {

        if (i == stones.size() - 1) {
            return true;
        }

        if (dp[i][lastJump] != -1) {
            return dp[i][lastJump];
        }

        for (int jump = lastJump - 1;
             jump <= lastJump + 1; jump++) {

            if (jump <= 0) continue;

            int nextPosition = stones[i] + jump;

            if (pos.count(nextPosition)) {
                int nextIndex = pos[nextPosition];

                if (solve(nextIndex, jump,
                          stones, pos, dp)) {
                    return dp[i][lastJump] = 1;
                }
            }
        }

        return dp[i][lastJump] = 0;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (n == 1) return true;
        if (stones[1] != 1) return false;

        unordered_map<int, int> pos;

        for (int i = 0; i < n; i++) {
            pos[stones[i]] = i;
        }

        vector<vector<int>> dp(
            n, vector<int>(n + 1, -1)
        );

        return solve(0, 0, stones, pos, dp);
    }
};
