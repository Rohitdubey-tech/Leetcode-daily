class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        string ans = "";
        int i=0;
        int n = s.size();
        while(i<n){
            while(i<n && s[i]==' '){
                i++;
            }
            if(i>=n){
                break;
            }
            int start = i;
            while(i<n && s[i] != ' '){
                i++;
            }
            string word = s.substr(start, i-start);
            reverse(word.begin(), word.end());
            if(!ans.empty()){
                ans += " ";
            }
            ans += word;
        }
        return ans;
    }
};