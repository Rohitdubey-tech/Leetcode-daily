class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size() > s.size()) return ans;
        vector<int>pFreq(26,0);
        vector<int>sFreq(26,0);
        for(char c : p){
            pFreq[c-'a']++;
        }
        int k = p.size();
        for(int i=0; i<k; i++){
            sFreq[s[i]-'a']++;
            if(pFreq == sFreq){
                ans.push_back(0);
            }
        }
        for(int i=k; i<s.size(); i++){
            sFreq[s[i]-'a']++;
            sFreq[s[i-k]-'a']--;
            if(pFreq == sFreq){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};