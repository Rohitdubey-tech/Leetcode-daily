class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, char>mp1;
        unordered_map<char, char>mp2;
        for(int i=0; i<s.length(); i++){
            char a = s[i];
            char b = t[i];

            if(mp1.count(a) && mp1[a] != b){
                return false;
            }
            if(mp2.count(b) && mp2[b] != a){
                return false;
            }
            mp1[a] = b;
            mp2[b] = a;
        }
        return true;
    }
};