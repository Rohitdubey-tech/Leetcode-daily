class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int>mp;
        for(int c : s){
            mp[c]++;
        }
        for(int c : t){
            mp[c]--;
        }
        for(auto& it : mp){
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
};