class Solution {
public:
    int characterReplacement(string s, int k) {
    int left = 0;
    int maxLen= 0;
    int maxFreq = INT_MIN;
    vector<int> freq(26,0);
    for(int right =0; right<s.size(); right++){
        freq[s[right]-'A']++;
        maxFreq = max(maxFreq, freq[s[right]-'A']);
        while((right-left+1)-maxFreq > k){
            freq[s[left]-'A']--;
            left++;
        }
        maxLen = max(maxLen, right-left+1);
    }
    return maxLen;

    }
};