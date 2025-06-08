class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> left(n, 0);   // Max profit for 1st transaction [0...i]
        vector<int> right(n, 0);  // Max profit for 2nd transaction [i...n-1]

        int min_price = prices[0];
        for (int i = 1; i < n; ++i) {
            min_price = min(min_price, prices[i]);
            left[i] = max(left[i - 1], prices[i] - min_price);
        }

        int max_price = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            max_price = max(max_price, prices[i]);
            right[i] = max(right[i + 1], max_price - prices[i]);
        }

        int max_profit = 0;
        for (int i = 0; i < n; ++i) {
            max_profit = max(max_profit, left[i] + right[i]);
        }

        return max_profit;
    }
};
