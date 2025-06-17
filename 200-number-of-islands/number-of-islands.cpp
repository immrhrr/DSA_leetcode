class Solution {
public:
    vector<int>h={1,0,-1,0};
    vector<int>v={0,-1,0,1};
    void dfs(vector<vector<char>>&grid,vector<vector<bool>>&vis,int r,int c){
        int m=grid.size();
        int n=grid[0].size();
        vis[r][c]=true;
        for(int i=0;i<4;i++){
            int nrow=r+h[i];
            int ncol=c+v[i];
            if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&vis[nrow][ncol]==false&&grid[nrow][ncol]=='1'){
                vis[nrow][ncol]=true;
                dfs(grid,vis,nrow,ncol);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    ans++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        return ans;
    }
};