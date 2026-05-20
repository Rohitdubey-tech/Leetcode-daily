class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        const int n=A.size();
        vector<int> ans(n, 0);
        bitset<101> seen;
        int cnt=0;
        for(int i=0; i<n; i++){
            int a=A[i], b=B[i];
            seen[2*a-1]=1; 
            cnt+=(seen[2*a]==1);
            seen[2*b]=1;
            cnt+=(seen[2*b-1]==1);
            ans[i]=cnt;
        }
        return ans;
    }
};