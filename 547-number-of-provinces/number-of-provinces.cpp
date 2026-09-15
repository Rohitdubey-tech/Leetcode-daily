class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city){
        visited[city] = true;
        for(int j=0; j<isConnected.size(); j++){
        if(isConnected[city][j] == 1 && visited[j] == false){
            dfs(isConnected, visited, j);
        }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>visited(n, false);
        int provinces = 0;
        for(int city = 0; city < n; city++){
            if(visited[city] == false){
                provinces++;
                dfs(isConnected, visited, city);
            }
        }
        return provinces;
    }
};