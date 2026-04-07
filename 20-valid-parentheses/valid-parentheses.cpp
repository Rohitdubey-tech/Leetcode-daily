class Solution {
public:
    bool isValid(string s) {
        stack<int>st;
        unordered_map<int, int>mp = {
            {')', '('},
            {'}','{'},
            {']','['}
        };
        for(char c : s){
            if(mp.find(c) == mp.end()){
                st.push(c);
            }
            else if(!st.empty() && mp[c]==st.top()){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();

    }
};