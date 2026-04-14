class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp;
        int left = 0;
        int maxLen = 0;
        for(int right =0; right<s.size(); right++){
            if(mp.find(s[right]) != mp.end()){
                left = max(left, mp[s[right]]+1);
            }
            mp[s[right]]=right;
            maxLen = max(maxLen, right - left +1);
        }
        return maxLen;
    }
};