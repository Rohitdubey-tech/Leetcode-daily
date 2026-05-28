class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int total =0;
        mp[0]=1;
        int prefixSum = 0;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            if(mp.find(prefixSum - k) != mp.end()){
                total += mp[prefixSum -k];
            }
            mp[prefixSum]++;
        }
        return total;
    }
};