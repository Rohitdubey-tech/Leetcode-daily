class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int n=nums.size();
        
        int sum=0,first=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            first+=(i*nums[i]);
        }
        
        int prev=first;
        for(int i=n-1;i>0;i--){
            prev=prev+sum-(nums[i]*n);
            first=max(first,prev);
        }

        return first;
    }
};