class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        bool resolved[n];
        memset(resolved, false, sizeof(resolved));
        int ans = 0;
        for(int j = 0; j < m; j ++){
            bool take = true;
            for(int i = 0; i < n - 1; i ++){
                if(resolved[i]) continue;
                if(strs[i][j] > strs[i + 1][j]){
                    take = false;
                    break;
                }
            }
            if(take){
                for(int i = 0; i < n - 1; i ++){
                    if(!resolved[i] && strs[i][j] < strs[i + 1][j]){
                        resolved[i] = true;
                    }
                }
            }
            else{
                ans += 1;
            }
        }
        return ans;
    }
};