class Solution {
public:
    int change(int tot, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(tot + 1, 0));

        // Base case: 1 way to make sum 0 (empty set)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= tot; j++) {
                unsigned long long notake = dp[i - 1][j]; // don't use coin[i-1]
                unsigned long long  take = 0;
                if (j - coins[i - 1] >= 0) {
                    take = dp[i][j - coins[i - 1]]; // use coin[i-1]
                }
                dp[i][j] = notake + take;
            }
        }

        return (int) dp[n][tot];
    }
};
