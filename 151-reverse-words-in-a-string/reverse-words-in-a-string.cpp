class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i=0; 
        int n = s.size();
        string ans;
        while( i< n){
            while( i< n && s[i] == ' '){
                i++;
            } 
            if(i>=n){
                break;
            }
            string word;
            while(i < n && s[i] != ' '){
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