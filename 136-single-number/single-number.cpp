class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(auto num : nums){
            mp[num]++;
        }
        for(auto it : mp ){
            if(it.second == 1){
                return it.first;
            }
        }
        return -1;
    }
};