class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int p = std::numeric_limits<int>::max();
        int n = -1;
        for (int v : nums) {
            int b = v <= p;
            n += b;
            nums[n] = (nums[n] & (b - 1)) + 1;
            p = v;
        }
        nums.resize(n + 1);
        int r = 0;
        p = 0;
        for (int v : nums) {
            r = max(r, min(p, v));
            r = max(r, max(p, v) / 2);
            p = v;
        }

        return r;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();