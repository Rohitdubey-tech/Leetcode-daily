class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long total = 0;
        for(int x:nums) total +=x;
        if(total % 2 == 0) return (int)nums.size()-1;
        return 0;

    }
};