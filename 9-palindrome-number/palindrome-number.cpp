class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int temp = x;
        long revNum = 0;
        while(x > 0){
            revNum = (revNum * 10) + x%10;
            x /= 10;
         }
         if(revNum == temp){
            return true;
         }
         else{
            return false;
         }
    }
};