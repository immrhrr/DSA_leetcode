class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) {
            return grid;
        }

        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<vector<int>> temp(2 * n - 1);

        // Step 1: Group elements by diagonals
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[j - i + n - 1].push_back(grid[i][j]);
            }
        }

        // Step 2: Sort diagonals
        for (int i = 0; i < 2 * n - 1; i++) {
            sort(temp[i].begin(), temp[i].end());
            if (i < n) {
                reverse(temp[i].begin(), temp[i].end()); // Reverse for upper half diagonals
            }
        }

        // Step 3: Reconstruct sorted matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = temp[j - i + n - 1].front(); // Get first element
                temp[j - i + n - 1].erase(temp[j - i + n - 1].begin()); // Remove it properly
            }
        }

        return ans;
    }
};
