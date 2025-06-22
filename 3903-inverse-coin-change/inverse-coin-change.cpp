class Solution {
public:
    int solveTabulation(vector<bool>& vis, int end, int need) {
        vector<vector<int>> dp(end, vector<int>(need + 1, 0));

        // Base case: 1 way to make sum 0
        for (int i = 0; i < end; ++i) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < end; ++i) {
            for (int sum = 1; sum <= need; ++sum) {
                // Not take i
                dp[i][sum] = dp[i - 1][sum];

                // Take i (if it's marked in vis and sum allows)
                if (vis[i] && sum - i >= 0) {
                    dp[i][sum] += dp[i][sum - i];
                }
            }
        }

        return dp[end - 1][need];
    }

    vector<int> findCoins(vector<int>& ways) {
        int n = ways.size();
        vector<bool> ans(n + 1, false);

        for (int i = 0; i < n; i++) {
            int cnt = solveTabulation(ans, i + 1, i + 1);  // [1..i] to form sum i+1

            if (cnt + 1 == ways[i]) {
                ans[i + 1] = true;
            } else if (cnt != ways[i]) {
                return {};
            }
        }

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (ans[i]) res.push_back(i);
        }

        return res;
    }
};
