class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        //down
        //right
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int down=0;
                int right=0;
                if(i==0&&j==0){
                    continue;
                }
                else{
                    if(j-1>=0){
                        right=dp[i][j-1];
                    }
                    if(i-1>=0){
                        down=dp[i-1][j];
                    }
                }
                dp[i][j]=down+right;
            }
        }
        return dp[m-1][n-1];
        
    }
};