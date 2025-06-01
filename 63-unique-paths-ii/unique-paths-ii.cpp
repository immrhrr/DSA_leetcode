class Solution {
public:
    int solve(int &m,int &n,int r,int c,vector<vector<int>>&dp,vector<vector<int>>&grid){
        if(r==m-1&&c==n-1)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int right=0;
        int bottom=0;
        if(c+1<n&&grid[r][c+1]==0){
            right=solve(m,n,r,c+1,dp,grid);
        }
        if(r+1<m&&grid[r+1][c]==0){
            bottom=solve(m,n,r+1,c,dp,grid);
        }
        return dp[r][c]=right+bottom;

    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        if(grid[0][0]==1||grid[m-1][n-1]==1)return 0;
        return solve(m,n,0,0,dp,grid);
        
        
    }
};