class Solution {
private:
    bool dfs(int r, int c, int pr, int pc,
             vector<vector<int>>& vis,
             vector<int>& row, vector<int>& col,
             vector<vector<char>>& grid, char ch) 
             {
        
        vis[r][c] = 1;
        for (int k = 0; k < 4; k++) 
        {
            int nr = r + row[k];
            int nc = c + col[k];
            if (nr >= 0 && nr < grid.size() && nc >= 0 && nc < grid[0].size()) 
            {
                if (grid[nr][nc] != ch) continue;
                if (!vis[nr][nc]) 
                {
                    if (dfs(nr, nc, r, c, vis, row, col, grid, ch))
                        return true;
                }
                else if (nr != pr || nc != pc) 
                {
                    return true;
                }
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> row={0,-1,0,1};
        vector<int> col={-1,0,1,0};
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (!vis[i][j]) {
                    if (dfs(i, j, -1, -1, vis, row, col, grid, grid[i][j])) 
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};