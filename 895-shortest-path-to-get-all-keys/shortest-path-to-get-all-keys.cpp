class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int k = 0;
        queue<vector<int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@') {
                    q.push({i, j, 0, 0});
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    k++;
                }
            }
        }
        vector<int> h = {1, 0, -1, 0};
        vector<int> v = {0, -1, 0, 1};
        int final_key_status_decimal = pow(2, k) - 1;
        

        vector<vector<vector<int>>> vis(m, vector<vector<int>>(n, vector<int>(1 << k, 0)));


        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int i = it[0];
            int j = it[1];
            int steps = it[2];
            int curr_key_status = it[3];
            if (curr_key_status == final_key_status_decimal) {
                return steps;
            }
            for (int ind = 0; ind < 4; ind++) {
                int nrow = i + h[ind];
                int ncol = j + v[ind];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    grid[nrow][ncol] != '#') {
                    // now chack whether it is a lock,key or walk
                    char ch = grid[nrow][ncol];
                    // lock
                    if (ch >= 'A' && ch <= 'Z') {
                        // agar lock hai toh check krna padega ki iska key hai
                        // ki nahi sabse pehle kaunsa lock hai
                        int lock = grid[nrow][ncol] - 'A';
                        if (vis[nrow][ncol][curr_key_status] == 0) {
                            if (curr_key_status & (1 << lock)) {
                                // now i can get into it
                                vis[nrow][ncol][curr_key_status] = 1;
                                q.push({nrow,ncol,steps+1,curr_key_status});
                            }
                        }
                    }
                    // key
                    else if (ch >= 'a' && ch <= 'z') {
                        int key = grid[nrow][ncol] - 'a';
                        int new_key_status=(curr_key_status|(1<<key));
                        if(vis[nrow][ncol][new_key_status]==0){
                            vis[nrow][ncol][new_key_status]=1;
                            q.push({nrow,ncol,steps+1,new_key_status});
                        }
                    }
                    // walk
                    else {
                        if (!vis[nrow][ncol][curr_key_status]) {
                            vis[nrow][ncol][curr_key_status] = 1;
                            q.push({nrow, ncol, steps + 1, curr_key_status});
                        }
                    }
                }
            }
        }
        return -1;
    }
};