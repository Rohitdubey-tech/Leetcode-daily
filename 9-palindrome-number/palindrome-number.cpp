class Solution {
public:
    bool isPalindrome(int x) {
        int dup = x;
        long revNum = 0;
        while(x>0){
            revNum = (revNum * 10) + x%10;
            x /=10;
        }
        if(revNum == dup ){
            return true;
        }
        else {
            return false;
        }
    }
};