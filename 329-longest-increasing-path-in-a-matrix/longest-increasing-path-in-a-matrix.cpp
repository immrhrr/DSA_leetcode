class Solution {
public:
    vector<int>dx={1,0,-1,0};
    vector<int>dy={0,-1,0,1};
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>&matrix,int row,int col){
        int n=matrix.size();
        int m=matrix[0].size();
        if(dp[row][col]!=-1)return dp[row][col];
        int temp=1;
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&matrix[nrow][ncol]>matrix[row][col]){
                temp=max(temp,1+dfs(matrix,nrow,ncol));
            }
        }
        return dp[row][col]= temp;

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]==-1){
                   ans=max(ans,dfs(matrix,i,j));
                }
            }
        }
        return ans;
    }
};