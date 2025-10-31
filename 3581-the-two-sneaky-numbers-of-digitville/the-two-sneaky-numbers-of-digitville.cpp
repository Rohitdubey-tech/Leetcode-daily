class Solution {
public:
    vector<int> getSneakyNumbers(const vector<int>& nums) {
        vector<int> cnt(101, 0), ans;
        for (int x : nums) {
            if (++cnt[x] == 2) {
                ans.push_back(x);
                if (ans.size() == 2) break;
            }
        }
        return ans;
    }
};
