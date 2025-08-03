class Solution {
public:
    int reverse(int x) {
        long revNum = 0;
        while(x != 0){
        int ld = x % 10;
        revNum = (revNum * 10) + ld;
        x = x/10;
        }
        return (revNum < INT_MIN || revNum > INT_MAX) ? 0 : revNum;
    }
};