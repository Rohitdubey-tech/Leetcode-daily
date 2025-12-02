class Solution {
public:
    int countTrapezoids(vector<vector<int>>& p) {
        const long long M=1e9+7, INV2=(M+1)/2;
        unordered_map<long long,long long> f;
        for(auto &x:p) f[x[1]]++;
        long long S=0, SS=0;
        for(auto &y:f) {
            long long c=y.second;
            if(c>=2){
                long long v=c*(c-1)/2%M;
                S=(S+v)%M;
                SS=(SS+v*v%M)%M;
            }
        }
        long long ans=( (S*S%M - SS + M) %M ) * INV2 %M;
        return ans;
    }
};