class Solution {
public:
    int smallestNumber(int n) {
        int k = 0;
        int temp = n;
        while (temp > 0) {
            ++k;
            temp >>= 1;
        }
        int x = (1 << k) - 1;
        if (x < n) x = (1 << (k + 1)) - 1;
        return x;
    }
};
