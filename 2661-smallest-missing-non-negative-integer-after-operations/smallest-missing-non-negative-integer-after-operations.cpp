class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int>count(value,0);
        for (int num : nums) {
            int r = ((num % value) + value) % value; 
            count[r]++;
        }
        for (int x = 0; ; x++) {
            int r = x % value;
            if (count[r] == 0) {
                return x;
            }
            count[r]--;
        }
        return -1; 
    }
};