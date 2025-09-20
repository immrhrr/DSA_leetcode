class Solution {
public:
    bool solve(vector<int>& arr, int curr, int ind, vector<vector<int>>& dp) {
        int n = arr.size();
        if (curr < 0) return false;
        if (curr == 0) return true;
        if (ind >= n) return false;

        if (dp[curr][ind] != -1) return dp[curr][ind];

        bool take = solve(arr, curr - arr[ind], ind + 1, dp);
        if (take) return dp[curr][ind] = true;

        bool notake = solve(arr, curr, ind + 1, dp);
        return dp[curr][ind] = notake;
    }

    bool canPartition(vector<int>& nums) {
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%2==1)return false;
        int sum=tot/2;
        vector<vector<int>> dp(sum + 1, vector<int>(nums.size() + 1, -1));
        return solve(nums, sum, 0, dp);
        
    }
};