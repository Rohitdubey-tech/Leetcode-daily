class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        int sign = 1;
        long long num = 0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='+' || s[i]=='-')){
            if(s[i]=='-'){
                sign = -1;
            }
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            num = num * 10 + (s[i]-'0');
            if(sign * num <= INT_MIN){
                return INT_MIN;
            }
            if(sign * num >= INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return sign* num;
    }
};