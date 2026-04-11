class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            mp[x].push_back(i);

            if (mp[x].size() >= 3) {
                int sz = mp[x].size();
                ans = min(ans, 2 * (mp[x][sz - 1] - mp[x][sz - 3]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};