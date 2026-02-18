class Solution {
public:
    string reverseWords(string s) {
        int i = s.length()-1;
        string result;
        while(i>=0){
            while(i>=0 && s[i]==' '){
                i--;
            }
            if(i<0) break;
            int end = i;
            while(i>=0 && s[i] != ' '){
                i--;
            }
            int start = i+1;
            if(!result.empty()) result += " ";
            result += s.substr(start, end-start +1);
        }
        return result;
    }
};