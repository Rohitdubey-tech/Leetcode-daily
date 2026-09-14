class Solution {
public:
    int dfs(vector<vector<int>>&grid, int r, int c){
        int rows = grid.size();
        int cols = grid[0].size();
        if(r<0 || r>=rows || c<0 || c>=cols){
            return 0;
        }
        if(grid[r][c]==0){
            return 0;
        }
        grid[r][c]=0;
        int area = 1;

        area += dfs(grid, r, c+1);
        area += dfs(grid, r, c-1);
        area += dfs(grid, r+1, c);
        area += dfs(grid, r-1, c);

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(grid[r][c]==1){
                    int area = dfs(grid, r, c);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};