class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.length();
        if (k > n) return false;

        int need = 1 << k;
        if (n - k + 1 < need) return false;

        unordered_set<string> seen;
        for (int i = 0; i + k <= n; i++) {
            seen.insert(s.substr(i, k));
            if ((int)seen.size() == need) return true; // early exit
        }
        return (int)seen.size() == need;
        
    }
};