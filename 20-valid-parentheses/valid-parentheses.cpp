class Solution {
public:
    bool isValid(string s) {
        unordered_map<int, int>mp={
            {'}','{'},
            {')','('},
            {']','['}
        };
        stack<int>st;
        for(char c : s){
            if(mp.find(c)==mp.end()){
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