class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        long long count = 1;  // A single element is always a valid descent period

        for (int i = 1; i < n; i++) {
            if (prices[i - 1] - prices[i] == 1) {
                count++;  // Extend the current descent period
            } else {
                ans += (count * (count + 1)) / 2;  // Sum of arithmetic series
                count = 1;  // Reset count
            }
        }

        ans += (count * (count + 1)) / 2;  // Add the last segment
        return ans;
    }
};
