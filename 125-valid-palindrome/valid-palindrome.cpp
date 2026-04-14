class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> st;
        string clean = "";
        for(char c:s){
            if(isalnum(c)){
                clean += tolower(c);
                st.push(tolower(c));
            }
        }
        for(char c: clean){
            if(c != st.top()) return false;
            st.pop();
        }
        return true;
    }
};