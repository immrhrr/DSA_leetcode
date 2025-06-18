class Solution {
public:
    vector<int>h={1,0,-1,0};
    vector<int>v={0,-1,0,1};
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        //{dist,i,j}
        pq.push({0,{0,0}});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int r=it.second.first;
            int c=it.second.second;
            if(r==m-1&&c==n-1)return d;
            for(int i=0;i<4;i++){
                int nrow=r+h[i];
                int ncol=c+v[i];
                if(d>dist[r][c]){
                    continue;
                }
                if(nrow>=0&&nrow<m&&ncol>=0&&ncol<n){
                    int cost=dist[nrow][ncol];
                    if(cost>d+grid[nrow][ncol]){
                        dist[nrow][ncol]=d+grid[nrow][ncol];
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }
                }
            }

        }
        return dist[m-1][n-1];
    }
};