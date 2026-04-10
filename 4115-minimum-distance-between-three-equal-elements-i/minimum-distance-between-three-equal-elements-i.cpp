class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < nums.size(); i++) {
            positions[nums[i]].push_back(i);
        }
        int minDist = INT_MAX;
        bool found = false;
        for (auto &p : positions) {
            vector<int> &indices = p.second;
            if (indices.size() >= 3) {
                for (int i = 0; i + 2 < indices.size(); i++) {
                    int dist = 2 * (indices[i + 2] - indices[i]);
                    minDist = min(minDist, dist);
                    found = true;
                }
            }
        }
        return found ? minDist : -1;
    }
};