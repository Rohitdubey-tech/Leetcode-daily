class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();
        if(m==0) return 0;
        for(int i=0; i<=n-m; i++){
            int j=0;
            while(j<m && haystack[i+j]==needle[j]){
                j++;
            }
            if(j==m) return i;
        }
        return -1;
    }
};