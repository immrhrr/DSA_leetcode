class Solution {
public:
    bool solve(vector<int>& arr, int ind, vector<int>& dp) {
        int n = arr.size();

        // (Bounds check assumed already handled by the caller)

        // 1) Base: found a zero
        if (arr[ind] == 0) 
            return true;

        // 2) If already visited, we’re in a cycle → fail fast
        if (dp[ind] != -1) 
            return dp[ind];

        // 3) Mark as visited/in-progress (assume “no” for now)
        dp[ind] = 0;

        // 4) Try both jumps
        bool canLeft = false, canRight = false;
        int left  = ind - arr[ind];
        int right = ind + arr[ind];

        if (left >= 0) {
            canLeft = solve(arr, left, dp);
        }
        if (right < n) {
            canRight = solve(arr, right, dp);
        }

        // 5) If either direction works, record “yes”
        return dp[ind] = (canLeft || canRight);
    }

    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return solve(arr, start, dp);
    }
};
