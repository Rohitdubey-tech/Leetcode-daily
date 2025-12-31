class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for(int num=0; num<nums.size(); num++){
            if(count == 0){
                candidate = nums[num];
            }
            if(nums[num]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
        
    }
};