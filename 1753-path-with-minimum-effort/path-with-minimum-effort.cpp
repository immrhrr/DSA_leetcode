class Solution {
public:
    vector<int> h = {1, 0, -1, 0};
    vector<int> v = {0, -1, 0, 1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int last = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for (int i = 0; i < 4; i++) {
                int nrow = r + h[i];
                int ncol = c + v[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int curr = heights[nrow][ncol];
                    int nval = max(abs(curr - heights[r][c]), last);
                    if (dist[nrow][ncol] > nval) {
                        dist[nrow][ncol] = nval;
                        pq.push({dist[nrow][ncol], {nrow, ncol}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};