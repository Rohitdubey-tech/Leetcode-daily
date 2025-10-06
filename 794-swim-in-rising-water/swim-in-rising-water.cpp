class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        visited[0][0] = 1;
        vector<int> dirs = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto [t, x, y] = pq.top();
            pq.pop();
            if (x == n - 1 && y == n - 1) return t;
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k + 1];
                
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({max(t, grid[nx][ny]), nx, ny});
                }
            }
        }
        return -1; 
    }
};