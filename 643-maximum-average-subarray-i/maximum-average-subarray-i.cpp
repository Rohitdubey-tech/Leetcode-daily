class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double sum =0;
        for(int i=0; i<k; i++){
            sum += nums[i];
        }
        double maxSum = sum;
        for(int i=k; i<n; i++){
            sum += nums[i]-nums[i-k];
            maxSum = max(maxSum, sum);
        }
        return maxSum/k;
    }
};