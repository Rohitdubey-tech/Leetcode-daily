class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        long long max_v = 0;
        long long k = (long long)k1 + k2;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            max_v = max(max_v, diff[i]);
        }
        long long l = 0, r = max_v, threshold = max_v;
        while (l <= r) {
            long long mid = l + (r - l) / 2;

            long long curr_cost = 0;
            for (long long d : diff) {
                if (d > mid) curr_cost += d - mid;
            }

            if (curr_cost < k) {
                threshold = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        long long op_used = 0;
        for (int i = 0; i < n; i++) {
            if (diff[i] > threshold) {
                op_used += diff[i] - threshold;
                diff[i] = threshold;
            }
        }
        long long remaining = k - op_used;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (remaining > 0 && diff[i] == threshold && diff[i] != 0) {
                diff[i]--;
                remaining--;
            }
            ans += diff[i] * diff[i];
        }

        return ans;
    }
};