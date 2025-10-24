class Solution {
public:
    int nextBeautifulNumber(int n) {
        while (true) {
            ++n;
            if (isBalanced(n)) {
                return n;
            }
        }
    }
private:
    bool isBalanced(int x) {
        vector<int> freq(10, 0);
        int temp = x;
        while (temp > 0) {
            int d = temp % 10;
            if (d == 0) return false;
            ++freq[d];
            temp /= 10;
        }
        for (int d = 1; d <= 9; ++d) {
            if (freq[d] != 0 && freq[d] != d) {
                return false;
            }
        }
        return true;
    }
};
