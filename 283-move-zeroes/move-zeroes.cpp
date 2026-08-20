class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        for(int num : nums){
            if(num != 0){
                nums[pos] = num;
                pos++;
            }
        }
            while(pos < n){
                nums[pos] = 0;
                pos++;
        }
        
    }
};