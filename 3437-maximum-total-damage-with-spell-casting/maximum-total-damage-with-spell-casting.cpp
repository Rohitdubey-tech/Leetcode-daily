class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<long long, long long> freq;
        for (int p : power) freq[p]++;
        vector<long long> vals;
        for (auto &it : freq) vals.push_back(it.first);
        sort(vals.begin(), vals.end());
        int n = vals.size();
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++) {
            long long gain = vals[i] * freq[vals[i]];
            long long include = gain;
            int j = i - 1;
            while (j >= 0 && vals[j] >= vals[i] - 2) j--;
            if (j >= 0) include += dp[j];
            long long exclude = (i > 0) ? dp[i - 1] : 0;
            dp[i] = max(include, exclude);
        }
        return dp[n - 1];
    }
};
