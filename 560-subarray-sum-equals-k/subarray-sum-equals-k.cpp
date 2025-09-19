class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int result = 0;
        int cumSum = 0;
        map.insert({0,1});
        for(int i=0; i<nums.size(); i++){
            cumSum += nums[i];
            if(map.find(cumSum - k) != map.end()){
                result += map[cumSum - k];
            }
            map[cumSum]++;
        }
        return result;

    }
};