class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, -1, 0, 1};
    int n=0;
    int m=0;
    bool bfs(int r, int c, vector<vector<char>>& grid,vector<vector<bool>>& vis) {
        char ch=grid[r][c];
        vis[r][c] = true;
        queue<vector<int>> q;
        q.push({r, c, -1, -1});
        //row,col,px,py
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it[0];
            int col = it[1];
            int prow = it[2];
            int pcol = it[3];
            for (int i = 0; i < 4; i++) {
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == ch) {
                        if(nrow==prow&&ncol==pcol)continue;
                    if (vis[nrow][ncol]) {
                        return true;
                    } else {
                        vis[nrow][ncol] = true;
                        q.push({nrow, ncol, row, col});
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == false) {
                    if (bfs(i, j, grid, vis)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};