class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int s = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int ans = 0;

        for (int x : nums) {
            if (x != 0) {
                leftSum += x;
            } else {
                if (leftSum * 2 == s) {
                    ans += 2;   
                } else if (abs(leftSum * 2 - s) == 1) {
                    ans += 1;   
                }
            }
        }

        return ans;
    }
};
