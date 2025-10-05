class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        function<void(int, int, vector<vector<bool>>&)> dfs = [&](int i, int j, vector<vector<bool>>& ocean) {
            ocean[i][j] = true;
            for (auto [dx, dy] : directions) {
                int x = i + dx;
                int y = j + dy;
                
                if (x >= 0 && y >= 0 && x < m && y < n && !ocean[x][y] && heights[x][y] >= heights[i][j]) {
                    dfs(x, y, ocean);
                }
            }
        };
        for (int i = 0; i < m; i++) dfs(i, 0, pacific);     
        for (int j = 0; j < n; j++) dfs(0, j, pacific);     
        for (int i = 0; i < m; i++) dfs(i, n-1, atlantic);  
        for (int j = 0; j < n; j++) dfs(m-1, j, atlantic);  
        vector<vector<int>> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};
