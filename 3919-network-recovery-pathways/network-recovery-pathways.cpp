#define ll long long
class Solution {
public:
    bool fun(ll mid, vector<vector<int>>& edges, vector<bool>& online, ll k){
        ll n = online.size();
        vector<vector<pair<ll,ll>>> g(n);
        vector<ll> dist(n,1e15);
        dist[0] = 0;
        for(auto& it : edges){
            ll a = it[0], b = it[1], cost = it[2];
            if(!online[a] || !online[b]) continue;
            if(cost<mid) continue;
            g[a].push_back({b,cost});
        }
        priority_queue<pair<ll,ll>> pq;
        pq.push({-0,0});
        while(pq.size()){
            auto it = pq.top(); pq.pop();
            ll d = -it.first, node = it.second;
            if(dist[node] < d) continue;
            for(auto pp : g[node]){
                ll adj = pp.first, edge = pp.second;
                if(d + edge < dist[adj]){
                    dist[adj] = d + edge;
                    pq.push({-dist[adj], adj});
                }
            }
        }
        return dist[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        ll lo = 0, hi = 1e9, ans = -1;
        while(lo <= hi){
            ll mid = (lo+hi)>>1;
            if(fun(mid, edges, online, k)){
                lo = mid+1;
                ans = mid;
            }
            else hi = mid-1;
        }
        return ans;
    }
};