class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map ={
            {')', '('},
            {'}','{'},
            {']', '['},
        };
        for(char c : s){
            if(map.find(c) == map.end()){
                st.push(c);
            }
            else if(!st.empty() && map[c]==st.top()){
                st.pop();
            }
            else{
                return false;
            }
        }
        return st.empty();
    }
};