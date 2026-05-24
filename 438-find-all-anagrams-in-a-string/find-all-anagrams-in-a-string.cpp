class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>freqp(26,0);
        vector<int>freqs(26,0);
        for(char c: p){
            freqp[c-'a']++;
        }
        int k = p.size();
        for(int i=0; i<s.size(); i++){
            freqs[s[i]-'a']++;
            if(i>=k){
                freqs[s[i-k]-'a']--;
            }
            if(freqp == freqs){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};