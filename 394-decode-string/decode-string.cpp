class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return solve(s, i);
    }
    string solve(string& s, int& i) {
        string ans = "";
        int num = 0;
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '[') {
                i++;
                string temp = solve(s, i);
                for (int j = 0; j < num; j++) {
                    ans += temp;
                }
                num = 0;
            }
            else {
                ans += s[i];
            }
            i++;
        }
        return ans;
    }
};