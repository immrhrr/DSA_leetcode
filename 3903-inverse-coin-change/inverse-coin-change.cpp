class Solution {
public:
    int solve(vector<bool>& vis, int start, int end, int need, vector<vector<int>>& dp) {
        if (need == 0) return 1;
        if (start >= end || need < 0) return 0;

        if (dp[start][need] != -1) return dp[start][need];

        int take = 0, notake = 0;

        if (vis[start]) {
            take = solve(vis, start, end, need - start, dp);
        }

        notake = solve(vis, start + 1, end, need, dp);

        return dp[start][need] = take + notake;
    }

    vector<int> findCoins(vector<int>& ways) {
        int n = ways.size();
        vector<bool> ans(n + 1, false);

        for (int i = 0; i < n; i++) {
            // dp[start][need]
            vector<vector<int>> dp(n + 1, vector<int>(i + 2, -1));
            int cnt = solve(ans, 1, i + 1, i + 1, dp);

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
