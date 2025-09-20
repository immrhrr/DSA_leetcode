class Solution {
public:
    // int solve(int m,int n,int i,int j,vector<vector<int>>&dp){
    //     if(i==m-1&&j==n-1)return 1;
    //     if(i>=m||j>=n)return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     int down=0;
    //     int right=0;
    //     down=solve(m,n,i+1,j,dp);
    //     right=solve(m,n,i,j+1,dp);
    //     return dp[i][j]= down+right;
    // }
    int uniquePaths(int m, int n) {
        // vector<vector<int>>dp(m,vector<int>(n,-1));
        // return solve(m,n,0,0,dp);
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                int left=0;
                int top=0;
                if(i-1>=0){
                    left=dp[i-1][j];
                }
                if(j-1>=0){
                    top=dp[i][j-1];
                }
                dp[i][j]=left+top;
            }
        }
        return dp[m-1][n-1];
    }
};