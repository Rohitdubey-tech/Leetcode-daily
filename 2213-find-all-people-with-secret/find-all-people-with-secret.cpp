class Solution {
public:
    using int2 = pair<int, int>;

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<int2>> adj(n);
        for (auto& meet : meetings) {
            int x = meet[0], y = meet[1], time = meet[2];
            adj[x].emplace_back(time, y);
            adj[y].emplace_back(time, x);
        }

        vector<int> known(n, INT_MAX);
        vector<int> result;

        priority_queue<int2, vector<int2>, greater<int2>> pq;
        pq.emplace(0, 0);
        pq.emplace(0, firstPerson);

        while (!pq.empty()) {
            auto [time, person] = pq.top();
            pq.pop();

            if (known[person] != INT_MAX) continue;

            known[person] = time;
            result.push_back(person);

            for (auto& [t, next] : adj[person]) {
                if (known[next] == INT_MAX && t >= time) {
                    pq.emplace(t, next);
                }
            }
        }

        return result;
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();