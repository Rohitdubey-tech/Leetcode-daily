class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int i=0;
        int j= 0;
        string ans = "";
        while(i<n || j<m){
            if(i < word1.size()){
            ans += word1[i];
            i++;
            }
            if(j < word2.size()){
                ans += word2[j];
                j++;
            }
        }
        return ans;
    }
};