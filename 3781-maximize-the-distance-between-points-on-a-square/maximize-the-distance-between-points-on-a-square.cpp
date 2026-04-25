class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        auto flatten = [&](vector<int>& p) -> long long {
            long long x = p[0], y = p[1];
            if (y == 0) return x;
            if (x == side) return side + y;
            if (y == side) return 3LL * side - x;
            return 4LL * side - y;
        };
        vector<long long> arr;
        for (auto &p : points) arr.push_back(flatten(p));
        sort(arr.begin(), arr.end());

        int n = arr.size();

        auto notValid = [&](long long d) {
            for (int i = 0; i < n; i++) {
                int ptr = i, cnt = 1;

                while (cnt < k) {
                    long long target = arr[ptr] + d;
                    int j = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

                    if (j == n) break;

                    ptr = j;
                    cnt++;

                    if (d + arr[ptr] > arr[i] + 4LL * side) {
                        cnt = 0;
                        break;
                    }
                }

                if (cnt == k) return false;
            }
            return true;
        };

        long long low = 0, high = side, ans = 0;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if (!notValid(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (int)ans;
    }
};