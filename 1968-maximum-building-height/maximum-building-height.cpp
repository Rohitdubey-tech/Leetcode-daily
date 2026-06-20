class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n-1});
        sort(restrictions.begin(), restrictions.end(), [&](vector<int>& a, vector<int>& b){
            return a[0] < b[0];
        });
        int x = 0, y = 0;
        int m = restrictions.size();
        vector<int> a1(m), a2(m);
        for(int i=0; i<m; i++){
            int nx = restrictions[i][0];
            a1[i] = min(y+nx-x, restrictions[i][1]);
            x = nx;
            y = a1[i];
        }
        x = n, y = n-1;
        for(int i=m-1; i>=0; i--){
            int nx = restrictions[i][0];
            a2[i] = min(restrictions[i][1], y+x-nx);
            x = nx;
            y = a2[i];
        }
        for(int i=0; i<m; i++)restrictions[i][1] = min(a1[i], a2[i]);
        int ans = 0;
        x = 1, y = 0;
        for(int i=0; i<m; i++){
            int yn = ((y-x)+(restrictions[i][0]+restrictions[i][1]))/2;
            ans = max(ans, yn);
            x = restrictions[i][0];
            y = restrictions[i][1];
        }
        return ans;
    }
};