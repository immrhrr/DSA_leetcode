class Solution {
public:
    int solve(vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp){
        int n=matrix.size();
        if(row>=n||col<0||col>=n){
            return 1e5;
        }
        if(row==n-1){
            return matrix[row][col];
        }
        if(dp[row][col]!=1e9)return dp[row][col];
        int temp=INT_MAX;
        for(int cd=-1;cd<=1;cd++){
            temp=min(temp,matrix[row][col]+solve(matrix,row+1,col+cd,dp));
        }
        return dp[row][col]= temp;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        int row=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
        for(int col=0;col<n;col++){
           ans=min(ans,solve(matrix,row,col,dp));
        }
        return ans;
    }
};