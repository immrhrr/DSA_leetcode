class Solution {
public:
    using VB    = vector<bool>;
    using VVB   = vector<VB>;
    using VVVB  = vector<VVB>;
    using VVVVB = vector<VVVB>;

    struct State {
        int row;
        int col;
        int energyLeft;
        int collectedMask;
    };

    vector<vector<int>> directions = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        int maxi = energy;
        
        int litterBit[20][20];
        int litterCount = 0;
        int sr = 0, sc = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                litterBit[r][c] = -1;
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litterBit[r][c] = litterCount;
                    litterCount++;
                }
            }
        }

        int allLitterCollected = (1 << litterCount) - 1;
        if (litterCount == 0) return 0;

        queue<State> q;
        q.push({sr, sc, maxi, 0});

        VVVVB vis(m, VVVB(n, VVB(maxi + 1, VB(1 << litterCount, false))));
        vis[sr][sc][maxi][0] = true;

        int moves = 0;

        while (!q.empty()) {
            int currsize = q.size();
            while (currsize--) {
                State curr = q.front();
                q.pop();

                if (curr.collectedMask == allLitterCollected) {
                    return moves;
                }

                if (curr.energyLeft == 0) {
                    continue;
                }

                for (auto &dir : directions) {
                    int nextR = curr.row + dir[0];
                    int nextC = curr.col + dir[1];

                    if (nextR < 0 || nextR >= m || nextC < 0 || nextC >= n) {
                        continue;
                    }

                    char cell = classroom[nextR][nextC];
                    if (cell == 'X') {
                        continue;
                    }

                    int nextEnergy = curr.energyLeft - 1;
                    int nextCollectedMask = curr.collectedMask;

                    if (cell == 'R') {
                        nextEnergy = maxi; // Recharge fully
                    } else if (cell == 'L') {
                        nextCollectedMask |= (1 << litterBit[nextR][nextC]);
                    }

                    if (!vis[nextR][nextC][nextEnergy][nextCollectedMask]) {
                        vis[nextR][nextC][nextEnergy][nextCollectedMask] = true;
                        q.push({nextR, nextC, nextEnergy, nextCollectedMask});
                    }
                }
            }
            moves++;
        }

        return -1;
    }
};