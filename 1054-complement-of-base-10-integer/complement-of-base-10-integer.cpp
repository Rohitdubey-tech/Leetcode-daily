class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0)
        return 1;
        
        int ans = 0 , power = 0;
        while(n){
            if(n%2 == 0)
            ans += pow(2,power);

            n /= 2;
            power++;
        }
        return ans;
    }
};