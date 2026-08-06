class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        unordered_set<int> st;
        int left = 0;
        for(int right = 0; right<s.size(); right++){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            length = max(length, right-left+1);
        }
        return length;
    }
};