class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        long long target=sum-x;
        if(target<0){
            return -1;
        }
        int left=0;
        int maxLen=-1;
        long long sumFind=0;
        for(int right=0;right<nums.size();right++){
            sumFind+=nums[right];
            while(sumFind>target){
                sumFind-=nums[left];
                left++;
            }
            if(sumFind==target){
                maxLen=max(maxLen,right-left+1);
            }
        }
        if(maxLen>=0){
            return nums.size()-maxLen;
        }
        return -1;
    }
};