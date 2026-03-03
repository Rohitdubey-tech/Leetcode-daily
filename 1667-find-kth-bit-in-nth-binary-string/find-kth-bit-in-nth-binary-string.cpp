class Solution {
public:
    char findKthBit(int n, int k) {
        bool flip = false;

        while (n > 1) {
            int mid = 1 << (n - 1);
            int len = (1 << n) - 1;

            if (k == mid) {
                return flip ? '0' : '1';
            }

            if (k > mid) {
                k = len - k + 1;
                flip = !flip;
            }

            n--;
        }

        return flip ? '1' : '0';
    }
};