class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;
        
        bool sign=true;
        if(dividend<0 && divisor>0) sign=false;
        if(dividend>=0 && divisor<0) sign =false;

        long long n=abs((long long)dividend);
        long long d=abs((long long)divisor);

        long long ans=0;
        while(n>=d){
            int c=0;
            while(n>=(d<<(c+1)))
                c++;
            
            ans+=(1LL<<c);
            n=n-(d<<c);
        }
        
        return sign?ans:-ans;
    }
};