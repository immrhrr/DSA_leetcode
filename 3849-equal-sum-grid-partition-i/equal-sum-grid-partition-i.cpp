class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long totalSum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                totalSum += grid[i][j];
            }
        }

        // If total sum is odd, equal partition is impossible
        if (totalSum % 2 != 0) return false;

        // Try horizontal cut (between rows)
        long long topSum = 0;
        for (int i = 0; i < n - 1; i++) { // cut after row i (i from 0 to n-2)
            long long currentRowSum = 0;
            for (int j = 0; j < m; j++) {
                currentRowSum += grid[i][j];
            }
            topSum += currentRowSum;
            long long bottomSum = totalSum - topSum;
            if (topSum == bottomSum) return true;
        }

        // Try vertical cut (between columns)
        long long leftSum = 0;
        for (int j = 0; j < m - 1; j++) { // cut after column j (j from 0 to m-2)
            long long currentColSum = 0;
            for (int i = 0; i < n; i++) {
                currentColSum += grid[i][j];
            }
            leftSum += currentColSum;
            long long rightSum = totalSum - leftSum;
            if (leftSum == rightSum) return true;
        }

        return false; // No valid partition found
    }
};
