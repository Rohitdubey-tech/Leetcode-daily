class Solution {
public:
    struct State {
        long long score = 0;
        vector<int> idx;
    };

    bool better(const State& a, const State& b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.idx < b.idx;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original_index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by ending point
        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            return x[1] < y[1];
        });

        vector<int> ends(n);

        for (int i = 0; i < n; i++)
            ends[i] = a[i][1];

        // Find previous non-overlapping interval
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] =
                lower_bound(ends.begin(), ends.end(), a[i][0])
                - ends.begin();
        }

        // dp[i][k] = best answer using first i intervals
        // while selecting at most k intervals
        vector<vector<State>> dp(n + 1, vector<State>(5));

        for (int i = 1; i <= n; i++) {

            // Skip current interval
            for (int k = 1; k <= 4; k++)
                dp[i][k] = dp[i - 1][k];

            // Take current interval
            for (int k = 1; k <= 4; k++) {

                State take = dp[prev[i - 1]][k - 1];

                take.score += a[i - 1][2];

                take.idx.push_back(a[i - 1][3]);

                sort(take.idx.begin(), take.idx.end());

                if (better(take, dp[i][k]))
                    dp[i][k] = take;
            }
        }

        return dp[n][4].idx;
    }
};