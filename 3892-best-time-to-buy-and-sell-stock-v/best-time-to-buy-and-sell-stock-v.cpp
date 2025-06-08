
class Solution {
    // dp[ind][remK][state] caches solve(prices, remK, state, ind)
    vector<vector<vector<long long>>> dp;
    int n;

    long long dfs(const vector<int>& prices, int remK, int state, int ind) {
        // Base cases
        if (ind >= n) 
            return (state == 0 ? 0 : LLONG_MIN);
        if (remK <= 0) 
            return (state == 0 ? 0 : LLONG_MIN);

        long long& memo = dp[ind][remK][state];
        if (memo != LLONG_MAX) 
            return memo;

        long long ans;
        if (state == 0) {
            // idle → open long, open short, or skip
            long long skip  = dfs(prices, remK,   0, ind + 1);

            long long openL = dfs(prices, remK,   1, ind + 1);
            long long rL    = (openL   == LLONG_MIN ? LLONG_MIN : openL   - prices[ind]);

            long long openS = dfs(prices, remK,   2, ind + 1);
            long long rS    = (openS   == LLONG_MIN ? LLONG_MIN : openS   + prices[ind]);

            ans = max({ skip, rL, rS });
        }
        else if (state == 1) {
            // holding long → close to idle or skip
            long long skip      = dfs(prices, remK,   1, ind + 1);

            long long closeIdle = dfs(prices, remK-1, 0, ind + 1);
            if (closeIdle != LLONG_MIN) 
                closeIdle += prices[ind];

            ans = max(skip, closeIdle);
        }
        else { // state == 2
            // holding short → close to idle or skip
            long long skip      = dfs(prices, remK,   2, ind + 1);

            long long closeIdle = dfs(prices, remK-1, 0, ind + 1);
            if (closeIdle != LLONG_MIN) 
                closeIdle -= prices[ind];

            ans = max(skip, closeIdle);
        }

        return memo = ans;
    }

public:
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        // DP dimensions: [n][k+1][3], init to LLONG_MAX
        dp.assign(n, vector<vector<long long>>(k+1, vector<long long>(3, LLONG_MAX)));
        return dfs(prices, k, 0, 0);
    }
};
