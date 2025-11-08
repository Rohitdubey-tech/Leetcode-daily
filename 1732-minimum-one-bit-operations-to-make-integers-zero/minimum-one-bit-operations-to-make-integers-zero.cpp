class Solution {
public:
    int minimumOneBitOperations(int n) {
        int res = 0;
        for (int i = 0; n; ++i) {
            if (n & 1) res = (1 << (i + 1)) - 1 - res;
            n >>= 1;
        }
        return res;
    }
};
