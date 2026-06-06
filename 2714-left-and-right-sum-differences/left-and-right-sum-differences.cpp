class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int right_sum=0;

        for(int i=0;i<nums.size();i++){
            right_sum+=nums[i];
        }

        int left_sum=0;
        vector<int> result;
        for(int i=0;i<nums.size();i++){
            right_sum -= nums[i];
            result.push_back(abs(left_sum-right_sum));
            left_sum += nums[i];
        }

        return result;
    }
};