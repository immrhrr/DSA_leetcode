class Solution:
    def find(self, i, j):
        if self.parent[i][j] == -1:
            return (i, j)
        self.parent[i][j] = self.find(self.parent[i][j][0], self.parent[i][j][1])
        return self.parent[i][j]
    
    def union(self, a, b, c, d):
        xa, ya = self.find(a, b)
        xb, yb = self.find(c, d)
        if (xa, ya) != (xb, yb):
            self.parent[xb][yb] = (xa, ya)
    
    def findMaxFish(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        self.parent = [[-1] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    for x, y in [(i - 1, j), (i, j - 1), (i + 1, j), (i, j + 1)]:
                        if 0 <= x < m and 0 <= y < n and grid[x][y] != 0:
                            self.union(i, j, x, y)
        res = Counter()
        res[-1] = 0
        for i in range(m):
            for j in range(n):
                if grid[i][j] != 0:
                    res[self.find(i, j)] += grid[i][j]
        return max(res.values())