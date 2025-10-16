class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 +str2 != str2 + str1) return "";
        int len1 = str1.size();
        int len2 = str2.size();
        int gcdLen = gcd(len1, len2);
        return str1.substr(0, gcdLen);
 }
 private:
 int gcd(int a, int b){
    return b ==0 ? a : gcd(b,a%b);
 }

};