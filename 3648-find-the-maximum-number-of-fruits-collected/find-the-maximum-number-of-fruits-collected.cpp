class Solution {
public:
    int solve2(vector<vector<int>>& fruits, int i, int j,vector<vector<int>>&dp) {
        int n = fruits.size();
        if (i == n - 1 && j == n - 1)
            return fruits[i][j]; // reached destination
        if (i < 0 || i >= n || j < 0 || j >= n||j>=i)
            return -1e5;  // invalid path
        if(dp[i][j]!=-1)return dp[i][j];
        int op1 = solve2(fruits, i - 1, j + 1,dp);
        int op2 = solve2(fruits, i, j+1,dp);
        int op3 = solve2(fruits, i + 1, j + 1,dp);

        return dp[i][j]= fruits[i][j] + max({op1, op2, op3});
    }

    int solve3(vector<vector<int>>& fruits, int i, int j,vector<vector<int>>&dp) {
        int n = fruits.size();
        if (i == n - 1 && j == n - 1)
            return fruits[i][j];
        if (i < 0 || i >= n || j < 0 || j >= n||i>=j)
            return -1e5;
        if(dp[i][j]!=-1)return dp[i][j];
        int op1 = solve3(fruits, i + 1, j - 1,dp);
        int op2 = solve3(fruits, i+1, j ,dp);
        int op3 = solve3(fruits, i + 1, j + 1,dp);

        return dp[i][j]= fruits[i][j] + max({op1, op2, op3});
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        int diag = 0;
        for (int i = 0; i < n; ++i)
            diag += fruits[i][i];
        vector<vector<int>>dp2(n,vector<int>(n,-1));
        vector<vector<int>>dp3(n,vector<int>(n,-1));
        int left = solve2(fruits, n - 1, 0,dp2);     // bottom-left to bottom-right
        int right = solve3(fruits, 0, n - 1,dp3);    // top-right to bottom-right

        return diag + left + right - 2 * fruits[n - 1][n - 1]; // adjust overlap
    }
};
