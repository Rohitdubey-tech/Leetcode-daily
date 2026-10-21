class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        bool flag = true;

        for(int i = 0; i < n; i++) {
            if(i > 0 && s[i] < s[i - 1]) {
                flag = false;
                break;
            }
        }

        if(flag) {
            return 0;
        }

        if(n == 2) {
            return -1;
        }

        char minChar = 'z';
        char maxChar = 'a';

        for(char ch : s) {
            minChar = min(minChar, ch);
            maxChar = max(maxChar, ch);
        }

        if(minChar == s[0] || maxChar == s[n - 1]) {
            return 1;
        }

        for(int i = 1; i < n - 1; i++) {
            if(s[i] == minChar || s[i] == maxChar) {
                return 2;
            }
        }

        return 3;
    }
};