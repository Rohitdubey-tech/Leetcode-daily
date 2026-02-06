class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i ++){
            int max_val = min((long long)2e9, (long long)k * nums[i]);
            int j = upper_bound(nums.begin(), nums.end(), max_val) - nums.begin();
            j --;
            ans = max(ans, j - i + 1);
        }
        return n - ans;
    }
};