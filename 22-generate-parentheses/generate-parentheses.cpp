class Solution {
    vector<string> ans;
    void backtrack(string& s, int open, int close, int n) {
        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        if (open < n) {
            s.push_back('(');
            backtrack(s, open + 1, close, n);
            s.pop_back();
        }
        if (close < open) {
            s.push_back(')');
            backtrack(s, open, close + 1, n);
            s.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        ans.clear();
        string s;
        s.reserve(2 * n);
        backtrack(s, 0, 0, n);
        return ans;
    }
};