class Solution {
public:
    int solve(vector<int>& prices, int k, int state, int ind,
                    vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if (ind >= n) {
            return state == 0 ? 0 : INT_MIN;
        }
        if (k == 0) {
            return state == 0 ? 0 : INT_MIN;
        }
        if (dp[k][state][ind] != INT_MAX) {
            return dp[k][state][ind];
        }
        int ans = 0;
        if (state == 0) {
            int buy = solve(prices, k, 1, ind + 1, dp);
            int skip = solve(prices, k, 0, ind + 1, dp);
            int net_buy =
                (buy == INT_MIN) ? INT_MIN : buy - prices[ind];
            ans = max({skip, net_buy});
        } else if (state == 1) {
            int sell = solve(prices, k - 1, 0, ind + 1, dp);
            int skip = solve(prices, k, 1, ind + 1, dp);
            int net_sell =
                (sell == INT_MIN) ? INT_MIN : sell + prices[ind];
            ans = max({skip, net_sell});
        } else {
            int buy = solve(prices, k - 1, 0, ind + 1, dp);
            int skip = solve(prices, k, 2, ind + 1, dp);
            int net_buy =
                (buy == INT_MIN) ? INT_MIN : buy - prices[ind];
            ans = max({skip, net_buy});
        }
        return dp[k][state][ind] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int state = 0;
        int ind = 0;
        int n = prices.size();
        vector<vector<vector<int>>> dp(k + 1,vector<vector<int>>(4, vector<int>(n + 1, INT_MAX)));
        return solve(prices, k, state, ind, dp);
    }
};