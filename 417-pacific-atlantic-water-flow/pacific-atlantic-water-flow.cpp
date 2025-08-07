class Solution {
public:
   vector<int>dx={1,0,-1,0};
   vector<int>dy{0,-1,0,1};
    void dfs(vector<vector<int>>&heights,int row,int col,vector<vector<bool>>&vis){
        int n=heights.size();
        int m=heights[0].size();
        vis[row][col]=true;
        for(int i=0;i<4;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]&&heights[nrow][ncol]>=heights[row][col]){
                vis[nrow][ncol]=true;
                dfs(heights,nrow,ncol,vis);
            }
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>>vis1(n,vector<bool>(m,false));
        vector<vector<bool>>vis2(n,vector<bool>(m,false));
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(vis1[i][0]==false){
                dfs(heights,i,0,vis1);
            }
            if(vis2[i][m-1]==false){
                dfs(heights,i,m-1,vis2);
            }

        }
        for(int i=0;i<m;i++){
            if(vis1[0][i]==false){
                dfs(heights,0,i,vis1);
            }
            if(vis2[n-1][i]==false){
                dfs(heights,n-1,i,vis2);
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis1[i][j]&&vis2[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};