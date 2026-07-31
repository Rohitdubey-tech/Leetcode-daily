class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>mp;
        for(char c : t){
            mp[c]++;
        }
        int left = 0;
        int minLength = INT_MAX;
        int start = 0;
        int required = t.size();
        for(int right = 0; right<s.size(); right++){
            if(mp[s[right]]>0){
                required--;
            }
            mp[s[right]]--;
            while(required==0){
                if(right-left+1 <minLength){
                    minLength = right-left+1;
                    start = left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0){
                    required++;
                }
                left++;
            }
        }
        if(minLength == INT_MAX){
            return "";
        }
        return s.substr(start, minLength);
    }
};