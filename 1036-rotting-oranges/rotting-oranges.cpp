class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int time = 0;
        queue<pair<int, int>> q;
        vector<int> h = {1, 0, -1, 0};
        vector<int> v = {0, -1, 0, 1};
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int tot=0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if(grid[i][j]==1){
                    tot++;
                }
            }
        }
        while (!q.empty()) {
            int mm = q.size();
            if(tot>0){
                time++;
            }
            
            while (mm--) {
                auto it = q.front();
                int r = it.first;
                int c = it.second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nrow = r + h[i];
                    int ncol = c + v[i];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n&&grid[nrow][ncol]==1&&vis[nrow][ncol]==false) {
                        vis[nrow][ncol]=true;
                        tot--;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
       if(tot>0)return -1;
        return time;
    }
};