class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int ans = 0;
        int oddCount = 0;
        int left = 0;
        for(int right=0; right<nums.size(); right++){
            if(nums[right] % 2 == 1){
                oddCount++;
            }
            while(oddCount > k){
                if(nums[left] % 2 == 1){
                    oddCount--;
                }
                left++;
            }
            ans += right-left+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k-1);
    }
};