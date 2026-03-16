class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> diag1(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> diag2(m + 1, vector<int>(n + 2, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                diag1[i + 1][j + 1] = diag1[i][j] + grid[i][j];
                diag2[i + 1][j] = diag2[i][j + 1] + grid[i][j];
            }
        }

        set<int> top3;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                top3.insert(grid[i][j]);
                if (top3.size() > 3) {
                    top3.erase(top3.begin()); // remove smallest
                }

                for (int k = 1; i - k >= 0 && i + k < m && j - k >= 0 && j + k < n; k++) {
                    int topR = i - k, topC = j;
                    int rightR = i, rightC = j + k;
                    int bottomR = i + k, bottomC = j;
                    int leftR = i, leftC = j - k;

                    long long border = 0;
                    // top -> right   (\)
                    border += diag1[rightR + 1][rightC + 1] - diag1[topR][topC];
                    // right -> bottom (/)
                    border += diag2[bottomR + 1][bottomC] - diag2[rightR][rightC + 1];
                    // left -> bottom  (\)
                    border += diag1[bottomR + 1][bottomC + 1] - diag1[leftR][leftC];
                    // top -> left     (/)
                    border += diag2[leftR + 1][leftC] - diag2[topR][topC + 1];
                    // corners counted twice
                    border -= grid[topR][topC];
                    border -= grid[rightR][rightC];
                    border -= grid[bottomR][bottomC];
                    border -= grid[leftR][leftC];

                    top3.insert(border);
                    if (top3.size() > 3) {
                        top3.erase(top3.begin()); // remove smallest
                    }
                }
            }
        }

        vector<int> ans;
        for (auto it = top3.rbegin(); it != top3.rend(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};