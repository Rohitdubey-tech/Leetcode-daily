class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> fullLakes; 
        set<int> dryDays; 
        for (int i = 0; i < n; ++i) {
            int lake = rains[i];
            if (lake == 0) {
                dryDays.insert(i);   
                ans[i] = 1;          
            } else {
                if (fullLakes.count(lake)) {
                    int lastRain = fullLakes[lake];
                    auto it = dryDays.upper_bound(lastRain);
                    if (it == dryDays.end()) {
                        return {}; 
                    }
                    int dryDay = *it;
                    ans[dryDay] = lake; 
                    dryDays.erase(it);  
                }
                fullLakes[lake] = i; 
                ans[i] = -1;
            }
        }
        return ans;
    }
};
