class Solution {
public:
    int findMin(vector<int>& nums) {
        int minElement = nums[0];
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<minElement){
                minElement = nums[i];
            }
        }
        return minElement;
    }
};