class Solution {
public:
    int count=0;
    void chess(int col,int n,vector<int>&leftrow,vector<int>&updiagonal,vector<int>&downdiagonal){
        if(n==col){
            count++;
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && updiagonal[n-1+col-row]==0 && downdiagonal[col+row]==0){
                leftrow[row]=1;
                updiagonal[n-1+col-row]=1;
                downdiagonal[col+row]=1;
                chess(col+1,n,leftrow,updiagonal,downdiagonal);
                leftrow[row]=0;
                updiagonal[n-1+col-row]=0;
                downdiagonal[col+row]=0;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int>leftrow(n,0),updiagonal(2*n-1,0),downdiagonal(2*n-1,0);
        chess(0,n,leftrow,updiagonal,downdiagonal);
        return count;
    }
};