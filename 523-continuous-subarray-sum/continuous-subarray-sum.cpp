class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        mp[0]=-1;
        int prefixSum = 0;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int rem = prefixSum % k;
            if(mp.find(rem) != mp.end()){
            if(i-mp[rem] >= 2){
                return true;
            }
            }
            else{
                mp[rem] = i;
            } 
        }
        return false;
    }
};