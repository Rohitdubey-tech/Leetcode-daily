class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        for (int i = 0; i < m; i++) {
            int emptyPos = n - 1;

            for (int j = n - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    emptyPos = j - 1;
                }
                else if (boxGrid[i][j] == '#') {
                    swap(boxGrid[i][j], boxGrid[i][emptyPos]);
                    emptyPos--;
                }
            }
        }

        vector<vector<char>> ans(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - 1 - i] = boxGrid[i][j];
            }
        }

        return ans;
    }
};