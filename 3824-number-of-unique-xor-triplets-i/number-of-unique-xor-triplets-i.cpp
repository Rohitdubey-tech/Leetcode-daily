class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int res = 1;
        while(res <= nums.size())
            res <<= 1;
        return res;
    }
};