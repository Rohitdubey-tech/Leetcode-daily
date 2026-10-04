class Solution {
public:
    void solve(double x, long long N, double &ans) {
        if (N == 0) {
            return;
        }

        if (N % 2 == 1) {
            ans = ans * x;
            N = N - 1;
        }
        else {
            x = x * x;
            N = N / 2;
        }

        solve(x, N, ans);
    }

    double myPow(double x, int n) {
        double ans = 1.0;
        long long N = n;
        bool neg = N < 0;

        if (neg) {
            N = -N;
        }

        solve(x, N, ans);

        if (neg) {
            return 1 / ans;
        }

        return ans;
    }
};