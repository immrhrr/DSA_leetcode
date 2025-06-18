class Solution {
public:
    vector<int> h = {1, 0, -1, 0};
    vector<int> v = {0, -1, 0, 1};

    void solve(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int temp, int& ans) {
        ans = max(ans, temp);

        int m = grid.size();
        int n = grid[0].size();

        for (int ind = 0; ind < 4; ind++) {
            int nrow = i + h[ind];
            int ncol = j + v[ind];
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] && grid[nrow][ncol] > 0) {

                vis[nrow][ncol] = true;
                solve(grid, nrow, ncol, vis, temp + grid[nrow][ncol], ans);
                vis[nrow][ncol] = false;
            }
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    vector<vector<bool>> vis(m, vector<bool>(n, false));
                    vis[i][j] = true;
                    solve(grid, i, j, vis, grid[i][j], ans);
                }
            }
        }
        return ans;
    }
};
