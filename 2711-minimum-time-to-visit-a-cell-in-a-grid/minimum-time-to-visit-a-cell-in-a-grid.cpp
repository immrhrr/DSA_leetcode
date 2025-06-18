class Solution {
public:
    vector<int> h = {1, 0, -1, 0};
    vector<int> v = {0, -1, 0, 1};
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int m = grid.size();
        int n = grid[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        pq.push({0, {0, 0}});
        vis[0][0] = true;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if (r == m - 1 && c == n - 1) {
                return t;
            }
            for (int i = 0; i < 4; i++) {
                int nrow = r + h[i];
                int ncol = c + v[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    vis[nrow][ncol] == false) {
                    if (t + 1 >= grid[nrow][ncol]) {
                        vis[nrow][ncol] = true;
                        pq.push({t + 1, {nrow, ncol}});
                    } else {
                        if (t % 2 == grid[nrow][ncol] % 2) {
                            vis[nrow][ncol] = true;
                            pq.push({grid[nrow][ncol] + 1, {nrow, ncol}});
                        } else {
                            vis[nrow][ncol] = true;
                            pq.push({grid[nrow][ncol], {nrow, ncol}});
                        }
                    }
                }
            }
        }
        return -1;
    }
};