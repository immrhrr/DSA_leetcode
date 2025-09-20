class Solution {
public:
    int solve(vector<vector<int>>&matrix,int r,int c,vector<vector<int>>&dp){
        int n=matrix.size();
        if(r>=n||c<0||c>=n){
            return 1e5;
        }
        if(r==n-1){
            return matrix[r][c];
        }
        int temp=INT_MAX;
        if(dp[r][c]!=1e9){
            return dp[r][c];
        }
        for(int i=-1;i<=1;i++){
            temp=min(temp,matrix[r][c]+solve(matrix,r+1,c+i,dp));
        }
        return dp[r][c]= temp;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9));
        for(int i=0;i<n;i++){
            ans=min(ans,solve(matrix,0,i,dp));
        }
        return ans;
        
    }
};