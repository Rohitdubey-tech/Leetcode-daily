class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<pair<int,int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        maze[entrance[0]][entrance[1]] = '+';
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while(!q.empty()) {
            auto front = q.front();
            q.pop();
            int r = front.first.first;
            int c = front.first.second;
            int steps = front.second;
            for(int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nc < 0 || nr >= m || nc >= n)
                    continue;
                if(maze[nr][nc] == '+')
                    continue;
                if(nr == 0 || nc == 0 || nr == m-1 || nc == n-1)
                    return steps + 1;
                maze[nr][nc] = '+';
                q.push({{nr, nc}, steps + 1});
            }
        }
        return -1;
    }
};