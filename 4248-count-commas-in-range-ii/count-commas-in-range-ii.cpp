class Solution {
public:
    long long countCommas(long long n) {
        if (n<=999) return 0;
        if (n<=999999) return n-999;
        long long prev=1e6-1e3;
        if (n<1e9) return (n+1-1e6)*2+prev;
        prev+=(2e9-2e6);
        if (n<1e12) return (n+1-1e9)*3+prev;
        prev+=(3e12-3e9);
        if (n<1e15) return (n+1-1e12)*4+prev;
        prev+=4LL*(1e15-1e12);
        return 5+prev;
    }
};