class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& res) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < res.size(); i++) {
            mp[res[i][0]].push_back(res[i][1]);
        }
        int count = 0;
        int rows = 0;
        for(auto it : mp) {
            rows++;
            vector<int> v = it.second;
            sort(v.begin(), v.end());
            for(int i = 2; i <= 6;) {
                auto lb = lower_bound(v.begin(), v.end(), i);
                if(lb == v.end() || *(lb) - i >= 4) {
                    count++;
                    i += 4;
                }
                else {
                    i += 2;
                }
            }
        }
        count += ((n - rows) * 2);
        return count;
    }
};