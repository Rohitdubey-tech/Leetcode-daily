class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";
        vector<int>freq(128,0);
        for(char c:t){
            freq[c]++;
        }
        int left = 0;
        int right = 0;
        int start = 0;
        int count = t.size();
        int minLen = INT_MAX;
        while(right<s.size()){
            if(freq[s[right]]>0){
                count--;
            }
            freq[s[right]]--;
            right++;
            while(count == 0){
                if(right-left < minLen){
                    minLen = right - left;
                    start = left;
                }
                freq[s[left]]++;
                if(freq[s[left]]>0){
                    count++;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};