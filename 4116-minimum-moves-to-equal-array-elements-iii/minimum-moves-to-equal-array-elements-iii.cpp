class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        int ans = 0;
        int maximum = nums[0];

        for (int num : nums) {
            if (maximum < num) {
                ans += (num - maximum) * count;
                maximum = num;
            } 
            else if (num < maximum) {
                ans += maximum - num;
            }

            count++;
        }

        return ans;
    }
};