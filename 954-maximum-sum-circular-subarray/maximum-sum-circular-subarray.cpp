class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax = 0;
        int maxSum = INT_MIN;
        int currMin = 0;
        int minSum = INT_MAX;
        int total = 0;
        for(int num : nums){
            currMax = max(num, currMax+num);
            maxSum = max(maxSum, currMax);

            currMin = min(num, currMin+num);
            minSum = min(minSum, currMin);

            total += num;
        }
        if(maxSum < 0){
            return maxSum;
        }
        return max(maxSum, total-minSum);
    }
};