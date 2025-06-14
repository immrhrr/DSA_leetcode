class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<int>>dist(n+1,vector<int>(n+1,1e9));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j){
                    dist[i][j]=0;
                    continue;
                }
                if(j-i==1){
                dist[i][j]=1;
                 dist[j][i]=1;
                continue;
               }
            }
        }
        if(x!=y){
            dist[x][y]=1;
            dist[y][x]=1;
        }
        for(int via=1;via<=n;via++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(dist[i][via]==1e9||dist[via][j]==1e9){
                        continue;
                    }
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        vector<int>ans(n,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dist[i][j]==0||dist[i][j]==1e9){
                    continue;
                }
                if(dist[i][j]>=1&&dist[i][j]<=n){
                    ans[dist[i][j]-1]++;
                }
            }
        }
        return ans;
    }
};