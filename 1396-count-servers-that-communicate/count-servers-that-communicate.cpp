class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    continue;
                }
                bool flag=false;
                for(int row=0;row<n;row++){
                    if(grid[row][j]==1&&row!=i){
                        ans++;
                        flag=true;
                        break;
                    }
                }
                if(flag){
                    continue;
                }

                for(int col=0;col<m;col++){
                    if(grid[i][col]==1&&col!=j){
                        ans++;
                        break;
                    }
                }
                //check rows
                //check cols
            }
        }
        return ans;
    }
};