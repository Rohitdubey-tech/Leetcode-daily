class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> frequency(26, 0);
        for(char c: s){
            frequency[c - 'a']++;
        }
        for(char c: t){
            frequency[c-'a']--;
        }
        for(int count: frequency){
            if(count != 0){
                return false;
            }
           
        }
         return true;
    }
};