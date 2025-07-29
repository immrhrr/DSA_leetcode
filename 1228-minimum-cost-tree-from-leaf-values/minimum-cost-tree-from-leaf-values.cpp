class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,vector<vector<int>>&memo) {
        if (i >= j) {
            return 0; 
        }
        if(memo[i][j]!=-1)return  memo[i][j];
        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            int temp = dp[i][k] * dp[k + 1][j] + solve(i, k, dp,memo) + solve(k + 1, j, dp,memo);
            ans = min(temp, ans);
        }
        return memo[i][j]= ans;
    }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); 
        for (int i = 0; i < n; i++) {
            dp[i][i] = arr[i];
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = max(dp[i][j - 1], arr[j]);
            }
        }
        vector<vector<int>>memo(n,vector<int>(n,-1));
        return solve(0, n - 1, dp,memo);
    }
};
