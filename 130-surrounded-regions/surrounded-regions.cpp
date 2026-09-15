class Solution {
public:
    void dfs(vector<vector<char>>& board, int r, int c){
        int rows = board.size();
        int cols = board[0].size();

        if(r<0 || r>= rows || c<0 || c>= cols){
            return;
        }
        if(board[r][c] != 'O'){
            return;
        }
        board[r][c]='#';
        dfs(board, r+1, c);
        dfs(board, r-1, c);
        dfs(board, r, c+1);
        dfs(board, r, c-1);
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for(int r=0; r<rows; r++){
            if(board[r][0]=='O'){
                dfs(board, r, 0);
            }
            if(board[r][cols-1]=='O'){
                dfs(board, r, cols-1);
            }
        }
        for(int c=0; c<cols; c++){
            if(board[0][c] == 'O'){
                dfs(board, 0, c);
            }
            if(board[rows-1][c]=='O'){
                dfs(board, rows-1, c);
            }
        }
        for(int r=0; r<rows; r++){
            for(int c=0; c<cols; c++){
                if(board[r][c]=='O'){
                    board[r][c]='X';
                }
                else if(board[r][c]=='#'){
                    board[r][c]='O';
                }
            }
        }
    }
};