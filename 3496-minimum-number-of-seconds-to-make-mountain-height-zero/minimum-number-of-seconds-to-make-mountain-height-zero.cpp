class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& t) {
        priority_queue<pair<long long, pair<int,int>>, 
        vector<pair<long long, pair<int,int>>>, 
        greater<pair<long long, pair<int,int>>>> pq;

        for(int i = 0; i < t.size(); i++){
            long long tm = t[i];
            pq.push({tm, {i, 1}});
        }

        long long res = 0;

        while(h > 0){
            auto cur = pq.top();
            pq.pop();

            long long tm = cur.first;
            int id = cur.second.first;
            int x = cur.second.second;

            res = tm;
            h--;

            if(h > 0){
                long long nx = x + 1;
                long long nt = (long long)t[id] * (nx * (nx + 1) / 2);
                pq.push({nt, {id, (int)nx}});
            }
        }

        return res;
    }
};