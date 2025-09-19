class Solution {
public:
    vector<int>h={1,0,-1,0};
    vector<int>v={0,-1,0,1};
    void dfs(vector<vector<bool>>&vis,vector<vector<char>>&grid,int r,int c){
        vis[r][c]=true;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=r+h[i];
            int ncol=c+v[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==false&&grid[nrow][ncol]=='1'){
                vis[nrow][ncol]=true;
                dfs(vis,grid,nrow,ncol);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int island=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&vis[i][j]==false){
                    dfs(vis,grid,i,j);
                    island++;
                }
            }
        }
        return island;
    }
};