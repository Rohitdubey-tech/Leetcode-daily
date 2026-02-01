class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int position = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[position] = nums[i];
                position++;
            }
        }
        while(position<nums.size()){
            nums[position] = 0;
            position ++;
        }
    }
};