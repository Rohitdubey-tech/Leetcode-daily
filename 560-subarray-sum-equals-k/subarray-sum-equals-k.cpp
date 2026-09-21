class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        int count = 0;
        int prefixSum = 0;
        mp[0] = 1;
        for(int num : nums){
            prefixSum += num;
            if(mp.find(prefixSum - k) != mp.end()){
                count += mp[prefixSum-k];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};