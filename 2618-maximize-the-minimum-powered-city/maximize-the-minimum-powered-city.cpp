class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> prefix(n+1,0);
        for (int i = 0; i < n; ++i) prefix[i+1] = prefix[i] + stations[i];
        auto baseAt = [&](int i){
            int L = max(0, i - r);
            int R = min(n - 1, i + r);
            return prefix[R+1] - prefix[L];
        };
        auto can = [&](long long m){
            long long used = 0, addSum = 0;
            queue<pair<int,long long>> q; 
            vector<long long> added(n,0);
            for (int i = 0; i < n; ++i) {
                while (!q.empty() && q.front().first < i) {
                    addSum -= q.front().second;
                    q.pop();
                }
                long long cur = baseAt(i) + addSum;
                if (cur < m) {
                    long long need = m - cur;
                    used += need;
                    if (used > k) return false;
                    int pos = min(n-1, i + r);
                    int expiry = pos + r;
                    if (expiry > n-1) expiry = n-1;
                    q.push({expiry, need});
                    addSum += need;
                }
            }
            return true;
        };
        long long low = 0, high = prefix[n] + k, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (can(mid)) { ans = mid; low = mid + 1; }
            else high = mid - 1;
        }
        return ans;
    }
};
