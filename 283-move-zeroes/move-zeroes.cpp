class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pos = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                nums[pos] = nums[i];
                pos++;
            }
        }
            while(pos < n){
                nums[pos]=0;
                pos++;
            }
        
    }
};