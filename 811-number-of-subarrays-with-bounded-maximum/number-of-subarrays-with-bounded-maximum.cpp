class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int lastValid = -1;
        int lastInvalid = -1;
        int ans = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>=left && nums[i]<=right){
                lastValid = i;
            }
            if(nums[i]>right){
                lastInvalid = i;
            }
            ans += max(0, lastValid - lastInvalid);
        }
        return ans;
    }
};