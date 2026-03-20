class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int minProduct = nums[0];
        int maxProduct = nums[0];
        int ans = nums[0];
        for(int i=1; i<n; i++){
            if(nums[i]<0) swap(maxProduct, minProduct);
                maxProduct = max(nums[i], nums[i] * maxProduct);
                minProduct = min(nums[i], nums[i] * minProduct);
                ans = max(ans, maxProduct);
        }
        return ans;
    }
};