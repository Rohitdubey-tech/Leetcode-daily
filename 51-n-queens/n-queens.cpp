class Solution {
public:
    void solve(int row, int n, vector<string> &curr,
               vector<bool> &col, vector<bool> &diag1,
               vector<bool> &diag2, vector<vector<string>> &res) {

        if (row == n) {
            res.push_back(curr);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (!col[c] && !diag1[row - c + n - 1] && !diag2[row + c]) {
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
                curr[row][c] = 'Q';

                solve(row + 1, n, curr, col, diag1, diag2, res);

                curr[row][c] = '.';
                col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        vector<bool> col(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);

        solve(0, n, board, col, diag1, diag2, res);
        return res;
    }
};