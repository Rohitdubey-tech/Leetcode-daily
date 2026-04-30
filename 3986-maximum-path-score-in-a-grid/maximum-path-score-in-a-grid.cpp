class Solution {
public:
    int n , m ;

    bool isSafe(int i , int j ){
    return i<n && j<m && i>=0 && j>=0;
    }

    
    int solve(int i , int j , vector<vector<int>>&grid , int k,vector<vector<vector<int>>>&dp){
        if(i>=n || j>=m)
        return 0;

        if(k<1 && grid[i][j]!=0)
        return INT_MIN;

        if(i==n-1 && j==m-1)
        return grid[i][j];

        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        
        int curr = (grid[i][j] == 0) ? 0 : 1;


        int bottom=INT_MIN;
        if(isSafe(i+1,j)){
        bottom=solve(i+1,j,grid,k-curr,dp);
        }

        int right=INT_MIN;
        if(isSafe(i,j+1)){
            right=solve(i,j+1,grid,k-curr,dp);
        }
        
        return dp[i][j][k]=grid[i][j]+max(right,bottom);

    }
    
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        int ans= solve(0,0,grid,k,dp);

        if(ans>=0)
        return ans;

        return -1;
    }
};