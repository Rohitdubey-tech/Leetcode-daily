class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if(s.size()<p.size()) return result;
        vector<int>pCount(26,0), sCount(26,0);
        int pLen = p.size();
        for(char c: p) pCount[c - 'a']++;
        for(int i=0; i<pLen; i++) sCount[s[i] - 'a']++;
        if(sCount == pCount) result.push_back(0);
        for(int i=pLen; i<s.size(); i++){
            sCount[s[i]-'a']++;
            sCount[s[i-pLen]-'a']--;
            if (sCount == pCount) result.push_back(i - pLen + 1);
        }
        return result;
    }
};