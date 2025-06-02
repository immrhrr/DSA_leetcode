class Solution {
public:
    int mod=1e9+7;
    int dfs(vector<vector<int>>&matrix,int r,int c,vector<vector<int>>&dp){
        if(dp[r][c]!=-1)return dp[r][c];
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>h={1,0,-1,0};
        vector<int>v={0,-1,0,1};
        int temp=1;
        for(int i=0;i<4;i++){
            int nrow=r+h[i];
            int ncol=c+v[i];
            if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&matrix[nrow][ncol]>matrix[r][c]){
                temp=(temp+dfs(matrix,nrow,ncol,dp))%mod;
               
            }
        }
        return dp[r][c]=temp;
    }
    int countPaths(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=(ans+(dfs(matrix,i,j,dp))%mod)%mod;
               
            }
        }
        return ans;
        

        
    }
};