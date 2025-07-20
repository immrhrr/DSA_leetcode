class Solution {
public:
    vector<int> h = {1, 0, -1, 0};
    vector<int> v = {0, -1, 0, 1};
    long long bfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,int row,int col){
        long long curr=0;
        int n=grid.size();
        int m=grid[0].size();
        curr+=grid[row][col];
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0;i<4;i++){
                int nrow=r+h[i];
                int ncol=c+v[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]==false&&grid[nrow][ncol]>0){
                    curr+=grid[nrow][ncol];
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }
        }
        return curr;

    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false && grid[i][j] > 0) {
                    long long temp = bfs(grid, vis, i, j) ;
                    if (temp % k == 0) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};