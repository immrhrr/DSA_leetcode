class Solution {
public:
    vector<int> h = {1, 0, -1, 0};
    vector<int> v = {0, -1, 0, 1};
    bool check(vector<vector<int>>&grid,int limit){
        if(grid[0][0]>limit)return false;
        int n=grid.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int r=it.first;
            int c=it.second;
            if(r==n-1&&c==n-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int nrow=r+h[i];
                int ncol=c+v[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n&&grid[nrow][ncol]<=limit&&vis[nrow][ncol]==false){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }

        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        //if(n==1)return 1;
        int low = 0;
        int high = 2500;
        int mid = 0;
        int ans = -1;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (check(grid, mid)) {
                ans = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};