class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int diff=0,ans=0;
        for(int i=1;i<n;i++){
            diff=nums[i]-nums[i-1];
            ans=max(diff,ans);
        }
        return ans;
    }
};