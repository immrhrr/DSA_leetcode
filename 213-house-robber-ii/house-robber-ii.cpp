class Solution {
public:
    int solve(vector<int>& nums, int ind, vector<int>& dp, int n) {
        if (ind >= n) return 0;
        if (dp[ind] != -1) return dp[ind];
        int take = nums[ind] + solve(nums, ind + 2, dp, n);
        int notake = solve(nums, ind + 1, dp, n);
        return dp[ind] = max(take, notake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];   // ✅ fix for single house

        vector<int> dp1(n + 1, -1), dp2(n + 1, -1);
        int zero = solve(nums, 0, dp1, n - 1); // rob [0 … n-2]
        int last = solve(nums, 1, dp2, n);     // rob [1 … n-1]
        return max(zero, last);
    }
};
