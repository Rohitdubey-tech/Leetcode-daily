class Solution {
public:
    int power(int x, int n){
        int power = 1;
        for(int i=0;i<n;i++){
            power *= x;
        }
        return power;
    }

    int countDigitOne(int n) {
        if(n==0) return 0;
        int k = 0;
        int count = 0;
        int digit = n/(power(10,k));
        while(!(digit<10)){
            k++;
            digit = n/(power(10,k));
        }
        while(n){
            if (k==0){
                count++;
                break;
            }
            count += (digit*(k*power(10,k-1)));
            if (digit > 1){
                count +=  power(10,k);
            }else if(digit==1){
                count += n-power(10,k)+1;
            }
            n = n%(power(10,k));
            k--;
            digit = n/(power(10,k));
        }
        return count;
    }
};