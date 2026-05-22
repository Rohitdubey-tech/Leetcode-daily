class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        for(char c: s){
            if(isalnum(c)){
                temp += tolower(c);
            }
        }
        string rev = temp;
        reverse(rev.begin(), rev.end());
        return temp == rev;
    }
};