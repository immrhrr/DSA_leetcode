class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                vis[i][0]=true;
            }
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
                vis[i][n-1]=true;
            }
        }
         for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
                vis[0][i]=true;
            }
            if(board[m-1][i]=='O'){
                q.push({m-1,i});
                vis[m-1][i]=true;
            }
        }
        vector<int>h={1,0,-1,0};
        vector<int>v={0,-1,0,1};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0;i<4;i++){
                int nrow=r+h[i];
                int ncol=c+v[i];
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n&&board[nrow][ncol]=='O'&&vis[nrow][ncol]==false){
                vis[nrow][ncol]=true;
                q.push({nrow,ncol});
            }
            }

        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false&&board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return;

        
    }
};