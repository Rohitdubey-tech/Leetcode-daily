class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        reverse(s.begin(), s.end());
        int i=0;
        while(i<s.size()){
            while(i<s.size() && s[i]==' '){
                i++;
            }
            if(i>=s.size()){
                break;
            }
            string word;
            while(i<s.size() && s[i] != ' '){
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if(!ans.empty()){
                ans += " ";
            }
            ans += word;
        }
        return ans;
    }
};