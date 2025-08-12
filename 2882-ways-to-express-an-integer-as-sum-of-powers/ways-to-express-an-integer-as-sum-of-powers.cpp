class Solution {
public:
    const int modulo = 1e9 + 7;  // Corrected modulo definition
    
    int f(vector<int>& arr, int limit, int index, vector<vector<int>>& dp) {
        if (limit == 0) {
            return 1;
        }
        else if (index < 0 || limit < 0) {
            return 0;
        }
        if (dp[limit][index] != -1) {
            return dp[limit][index];
        }
        if (arr[index] <= limit) {
            dp[limit][index] = (f(arr, limit - arr[index], index - 1, dp) + f(arr, limit, index - 1, dp)) % modulo;
        } else {
            dp[limit][index] = f(arr, limit, index - 1, dp) % modulo;
        }
        return dp[limit][index];
    }

    int numberOfWays(int n, int x) {
        vector<int> arr;
        int temp = 1;
        // Fill the arr vector with powers of temp^x while temp^x <= n
        while (pow(temp, x) <= n) {
            arr.push_back(pow(temp, x));  // Store temp^x in arr
            temp++;
        }
        vector<vector<int>> dp(n + 1, vector<int>(arr.size() + 1, -1));  // DP table initialization
        return f(arr, n, arr.size() - 1, dp);
    }
};
