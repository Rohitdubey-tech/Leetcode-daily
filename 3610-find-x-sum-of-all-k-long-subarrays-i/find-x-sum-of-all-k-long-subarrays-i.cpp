class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> ans(n - k + 1);
        unordered_map<int,int> cnt;
        multiset<pair<int,int>> top, bot;
        long long sumTop = 0;
        auto add = [&](int v) {
            if (cnt[v] > 0) {
                pair<int,int> p = {cnt[v], v};
                if (top.erase(p)) sumTop -= (long long)p.first * p.second;
                else bot.erase(p);
            }
            cnt[v]++;
            bot.insert({cnt[v], v});
        };
        auto rem = [&](int v) {
            pair<int,int> p = {cnt[v], v};
            if (cnt[v] > 0) {
                if (top.erase(p)) sumTop -= (long long)p.first * p.second;
                else bot.erase(p);
            }
            cnt[v]--;
            if (cnt[v] > 0) bot.insert({cnt[v], v});
        };
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= k) rem(nums[i - k]);
            while (!bot.empty() && (int)top.size() < x) {
                auto p = *prev(bot.end());
                bot.erase(prev(bot.end()));
                top.insert(p);
                sumTop += (long long)p.first * p.second;
            }
            while (!bot.empty() && !top.empty() && *prev(bot.end()) > *top.begin()) {
                auto pB = *prev(bot.end());
                bot.erase(prev(bot.end()));
                auto pT = *top.begin();
                top.erase(top.begin());
                sumTop -= (long long)pT.first * pT.second;
                sumTop += (long long)pB.first * pB.second;
                bot.insert(pT);
                top.insert(pB);
            }
            if (i >= k - 1) {
                ans[i - k + 1] = (int)sumTop;
            }
        }
        return ans;
    }
};
