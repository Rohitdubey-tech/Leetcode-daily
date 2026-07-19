class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int length = 0;
        int left = 0;
        unordered_set<int> st;
        for(int right = 0; right < n; right++){
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