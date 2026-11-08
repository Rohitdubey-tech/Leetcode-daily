class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        int required = t.size();
        int left = 0;
        string ans = "";
        vector<int>freq(128,0);
        for(char ch : t){
            freq[ch]++;
        }
        int start = 0;
        int minLen = INT_MAX;
        for(int right = 0; right < s.size(); right++){
            if(freq[s[right]]>0){
                required--;
            }
            freq[s[right]]--;
            while(required == 0){
                if(right - left + 1 < minLen){
                    minLen = right - left + 1;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]> 0){
                    required++;
                }
                left++;
            }

        }
        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);
    }
};