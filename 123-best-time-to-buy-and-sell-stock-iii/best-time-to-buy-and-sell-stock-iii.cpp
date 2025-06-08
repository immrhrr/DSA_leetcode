
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1Cost   = INT_MAX;  // min price to buy first stock
        int t2Cost   = INT_MAX;  // effective min price to buy second stock (price - t1Profit)
        int t1Profit = 0;        // max profit after first sell
        int t2Profit = 0;        // max profit after second sell

        for (int p : prices) {
            // For first transaction:
            t1Cost   = min(t1Cost, p);
            t1Profit = max(t1Profit, p - t1Cost);

            // For second transaction (we reinvest t1Profit):
            t2Cost   = min(t2Cost, p - t1Profit);
            t2Profit = max(t2Profit, p - t2Cost);
        }

        return t2Profit;
    }
};
