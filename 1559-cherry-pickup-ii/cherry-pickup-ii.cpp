class Solution {
public:
    int solve(vector<vector<int>>& grid, int r, int c1, int c2,
              vector<vector<vector<int>>>& dp) {
        int rows = grid.size();
        int cols = grid[0].size();
        if (c1 < 0 || c2 < 0 || c1 >= cols || c2 >= cols || r >= rows) {
            return -1e5;
        }
        if (r == rows - 1) {
            if (c1 == c2) {
                return grid[r][c1];
            } else {
                return grid[r][c1] + grid[r][c2];
            }
        }
        if (dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }
        int maxi = INT_MIN;
        for (int d1 = -1; d1 <= 1; d1++) {
            for (int d2 = -1; d2 <= 1; d2++) {
                if (c1 == c2) {
                    maxi = max(maxi, grid[r][c1] + solve(grid, r + 1, c1 + d1,c2 + d2, dp));
                } else {
                    maxi =max(maxi, grid[r][c1] + grid[r][c2] + solve(grid, r + 1, c1 + d1, c2 + d2, dp));
                }
            }
        }
        return dp[r][c1][c2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<vector<int>>> dp(
            r + 1, vector<vector<int>>(c + 1, vector<int>(c + 1, -1)));
        return solve(grid, 0, 0, c - 1, dp);
    }
};