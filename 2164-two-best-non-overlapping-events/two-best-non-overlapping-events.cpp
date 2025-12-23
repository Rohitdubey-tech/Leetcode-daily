class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int best = 0;
        int ans = 0;

        for(auto&e : events){
            int start = e[0], end = e[1], val = e[2];
            while(!pq.empty() && pq.top().first < start){
                best = max(best, pq.top().second);
                pq.pop();
            }
            ans = max(ans, best + val);
            pq.push({end, val});
        }
        return ans;
    }
};