class Solution {
public:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, 
    vector<bool>& visited, int & count){
        visited[node] = true;
        for(auto it : adj[node]){
            int nextCity = it.first;
            int direction = it.second;
            if(!visited[nextCity]){
                count += direction;
                dfs(nextCity, adj, visited, count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});

        }
        vector<bool>visited(n, false);
        int count = 0;
        dfs(0, adj, visited, count);
        return count;
    }
};