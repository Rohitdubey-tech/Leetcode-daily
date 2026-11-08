class Solution {
public:
    double dfs(string src, string dest, unordered_map<string, vector<pair<string, double>>>& adj, unordered_set<string>& visited){
        if(adj.find(src) == adj.end()){
            return -1.0;
        }
        if(src == dest){
            return 1.0;
        }
        visited.insert(src);
        for(auto it : adj[src]){
            string next = it.first;
            double weight = it.second;
            if(visited.find(next) == visited.end()){
                double result = dfs(next, dest, adj, visited);
                if(result != -1.0){
                    return weight * result;

                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>>adj;
        for(int i=0; i<equations.size(); i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0/val});
        }
        vector<double>ans;
        for(auto query : queries){
            string src = query[0];
            string dest = query[1];
            unordered_set<string>visited;
            double result = dfs(src, dest, adj, visited);
            ans.push_back(result);
        }
        return ans;
    }
};