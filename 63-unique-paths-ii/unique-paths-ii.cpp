class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>&grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[m-1][n-1]==1)return 0;
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[0][0]=1;
        if(grid[0][0]==1){
            dp[0][0]=0;
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0)continue;
                if(grid[i][j]==1)continue;
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