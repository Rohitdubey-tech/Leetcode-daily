class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        const int MOD = 1e9 + 7;
        vector<int>sorted(nums1);
        sort(sorted.begin(), sorted.end());
        long long total= 0;
        long long maxGain = 0;
        for(int i=0; i<nums1.size(); i++){
            int diff = abs(nums1[i] - nums2[i]);
            total += diff;
            auto it = lower_bound(sorted.begin(), sorted.end(), nums2[i]);
            if(it != sorted.end()){
                int newDiff = abs(*it - nums2[i]);
                maxGain = max(maxGain, (long long)(diff - newDiff));

            }
            if(it!= sorted.begin()){
                --it;
                int newDiff = abs(*it - nums2[i]);
                maxGain = max(maxGain, (long long)(diff - newDiff));

            }

        }
        return (total - maxGain) % MOD;
    }
};