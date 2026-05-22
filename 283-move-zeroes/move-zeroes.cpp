class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>temp;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                temp.push_back(nums[i]);
            }
        }
        int k = temp.size();
        for(int i=0; i<k; i++){
            nums[i]=temp[i];
        }
        for(int i=k; i<n; i++ ){
            nums[i]=0;
        }
    }
};