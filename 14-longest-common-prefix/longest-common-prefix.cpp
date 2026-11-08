class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        for(int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for(int j = 1; j < n; j++) {
                if(i >= strs[j].size() || strs[j][i] != ch) {
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0];
    }
};