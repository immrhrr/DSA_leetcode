class Solution {
public:
    int solve(vector<vector<int>>&triangle,int row,int col,vector<vector<int>>&dp){
        int n=triangle.size();
        int m=triangle[row].size();
        if(row>=n||col<0||col>=m){
            return 1e5;
        }
        if(row==n-1){
            return triangle[row][col];
        }
        if(dp[row][col]!=1e9)return dp[row][col];
        int temp=INT_MAX;
        int op1=triangle[row][col]+solve(triangle,row+1,col,dp);
        int op2=triangle[row][col]+solve(triangle,row+1,col+1,dp);
        temp=min({temp,op1,op2});
        return dp[row][col]= temp;
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,1e9));
        return solve(triangle,0,0,dp);
    }
};