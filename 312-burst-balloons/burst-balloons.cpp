class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& nums, int i, int j) {
        if (i > j) {
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans = INT_MIN;
        int temp = 0;
        for (int k = i; k <= j; k++) {
            int l = nums[i - 1];
            int r = nums[j + 1];
            temp = (l * nums[k] * r) + solve(nums, i, k - 1) +
                   solve(nums, k + 1, j);
            ans = max(ans, temp);
        }
        return dp[i][j]= ans;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+2,vector<int>(n+2,-1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solve(nums, 1, n);
    }
};