class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> h = {1, 0, -1, 0};
        vector<int> v = {0, -1, 0, 1};
        int m = maze.size();
        int n = maze[0].size();
        int r = entrance[0];
        int c = entrance[1];
        maze[r][c] = '+';
        queue<pair<int, int>> q;
        q.push({r, c});
        int ans = 0;
        while (!q.empty()) {
            int mm = q.size();
            ans++;
            while (mm--) {
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second;
                for (int i = 0; i < 4; i++) {
                    int nrow = row + h[i];
                    int ncol = col + v[i];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                        maze[nrow][ncol] == '.') {
                        if (nrow == 0 || nrow == m - 1 || ncol == 0 ||
                            ncol == n - 1)
                            return ans;
                        q.push({nrow, ncol});
                        maze[nrow][ncol] = '+';
                    }
                }
            }
        }
        return -1;
    }
};