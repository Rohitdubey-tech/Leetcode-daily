class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<long long> xs;
        vector<array<long long,4>> events;
        for (auto &s : squares) {
            long long x = s[0], y = s[1], l = s[2];
            xs.push_back(x);
            xs.push_back(x + l);
            events.push_back({y, x, x + l, 1});
            events.push_back({y + l, x, x + l, -1});
        }
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        int n = xs.size();
        vector<long long> cnt(4 * n), len(4 * n);
        auto upd = [&](auto&& self, int node, int l, int r, int ql, int qr, int v) -> void {
            if (qr <= l || r <= ql) return;
            if (ql <= l && r <= qr) cnt[node] += v;
            else {
                int m = (l + r) / 2;
                self(self, node*2, l, m, ql, qr, v);
                self(self, node*2+1, m, r, ql, qr, v);
            }
            if (cnt[node] > 0) len[node] = xs[r] - xs[l];
            else if (l + 1 == r) len[node] = 0;
            else len[node] = len[node*2] + len[node*2+1];
        };
        sort(events.begin(), events.end());
        vector<pair<long double,long double>> slabs;
        long long prevY = events[0][0];
        long double area = 0;
        for (int i = 0; i < (int)events.size(); ) {
            long long y = events[i][0];
            long long dy = y - prevY;
            if (dy > 0 && len[1] > 0) {
                slabs.push_back({(long double)prevY, (long double)len[1]});
                area += (long double)len[1] * dy;
            }
            while (i < (int)events.size() && events[i][0] == y) {
                int l = lower_bound(xs.begin(), xs.end(), events[i][1]) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), events[i][2]) - xs.begin();
                upd(upd, 1, 0, n-1, l, r, events[i][3]);
                i++;
            }
            prevY = y;
        }
        long double half = area / 2.0;
        long double cur = 0;
        prevY = events[0][0];
        int idx = 0;
        sort(events.begin(), events.end());
        fill(cnt.begin(), cnt.end(), 0);
        fill(len.begin(), len.end(), 0);
        for (int i = 0; i < (int)events.size(); ) {
            long long y = events[i][0];
            long long dy = y - prevY;
            if (dy > 0 && len[1] > 0) {
                long double slabArea = (long double)len[1] * dy;
                if (cur + slabArea >= half) {
                    long double need = half - cur;
                    return (double)(prevY + need / (long double)len[1]);
                }
                cur += slabArea;
            }
            while (i < (int)events.size() && events[i][0] == y) {
                int l = lower_bound(xs.begin(), xs.end(), events[i][1]) - xs.begin();
                int r = lower_bound(xs.begin(), xs.end(), events[i][2]) - xs.begin();
                upd(upd, 1, 0, n-1, l, r, events[i][3]);
                i++;
            }
            prevY = y;
        }
        return (double)prevY;
    }
};