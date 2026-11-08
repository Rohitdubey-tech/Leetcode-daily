class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;
        for(int right = 0; right<s.size(); right++){
            freq[s[right]-'A']++;
            maxFreq = max(maxFreq, freq[s[right]-'A']);
            int windowSize = right - left + 1;
            if(windowSize - maxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};