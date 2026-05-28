class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>mp;
        mp[0]=1;
        int prefixSum = 0;
        int count = 0;
        for(int num : nums){
            prefixSum += num;
            if(mp.find(prefixSum - goal) != mp.end()){
                count += mp[prefixSum - goal];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};