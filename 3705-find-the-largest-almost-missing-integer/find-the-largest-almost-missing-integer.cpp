class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            int t=-1;
            for(int i=0;i<n;i++) if(nums[i]>t) t=nums[i];
            return t;
        }
        if(k==1){
            vector<int> z(51,0);
            int t=-1;
            for(int i=0;i<n;i++) z[nums[i]]++;
            for(int i=0;i<n;i++) if(z[nums[i]]==1 && nums[i]>t) t=nums[i];
            return t;
        }
        if(nums[0]==nums[n-1]) return -1;
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[0]) nums[0]=-1;
            if(nums[i]==nums[n-1]) nums[n-1]=-1;
            if(nums[0]==-1 && nums[n-1]==-1) return -1;
        }
        if(nums[n-1]==-1) return nums[0];
        else if(nums[0]==-1) return nums[n-1];
        return max(nums[0],nums[n-1]);
    }
};