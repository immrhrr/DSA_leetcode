class Solution {
public:
    vector<int> h = {1, 0, -1, 0};
    vector<int> v = {0, -1, 0, 1};

    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c) {
        int n = grid.size();
        vis[r][c] = true;
        queue<pair<int, int>> q;
        q.push({r, c});
        int cnt = 1;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for (int i = 0; i < 4; i++) {
                int nrow = row + h[i];
                int ncol = col + v[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = true;
                    cnt++;
                    q.push({nrow, ncol});
                }
            }
        }
        return cnt;
    }

    void update(vector<vector<int>>& grid, vector<vector<int>>& count, int r, int c, int val, vector<vector<pair<int,int>>>& parent) {
        int n = grid.size();
        queue<pair<int, int>> q;
        q.push({r, c});
        count[r][c] = val;
        parent[r][c] = {r, c};  // fixed: now representative is consistent
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int row = it.first;
            int col = it.second;
            for (int i = 0; i < 4; i++) {
                int nrow = row + h[i];
                int ncol = col + v[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] == 1 && count[nrow][ncol] == -1) {
                    q.push({nrow, ncol});
                    count[nrow][ncol] = val;
                    parent[nrow][ncol] = {r, c};  // assign same representative
                }
            }
        }
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<int>> count(n, vector<int>(n, -1));
        vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(n, {-1, -1}));  // initialized

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    int val = bfs(grid, vis, i, j);
                    update(grid, count, i, j, val, parent);
                }
            }
        }

        int ans = 0;
        bool hasZero = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans, count[i][j]);
                } else {
                    hasZero = true;
                    int possible = 1;
                    set<pair<int, int>> st;
                    for (int k = 0; k < 4; k++) {
                        int nrow = i + h[k];
                        int ncol = j + v[k];
                        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n &&
                            grid[nrow][ncol] == 1 &&
                            st.find(parent[nrow][ncol]) == st.end()) {
                            possible += count[nrow][ncol];
                            st.insert(parent[nrow][ncol]);
                        }
                    }
                    ans = max(ans, possible);
                }
            }
        }

        return hasZero ? ans : n * n;  // handle all-1 grid case
    }
};
