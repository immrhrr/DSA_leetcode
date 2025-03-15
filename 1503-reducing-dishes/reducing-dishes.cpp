class Solution {
public:
    int solve(vector<int>& sat, int idx, int f,vector<vector<int>>&dp) {
        if (idx < 0) {
            return 0;
        }
        if(dp[idx][f]!=INT_MIN){
            return dp[idx][f];
        }
        int take = 0;
        int notake = 0;
        take = f * sat[idx] + solve(sat, idx - 1, f + 1,dp);
        notake = solve(sat, idx - 1, f,dp);
        return dp[idx][f]=max(take, notake);
    }
    int maxSatisfaction(vector<int>& sat) {
        sort(sat.begin(), sat.end());
        reverse(sat.begin(),sat.end());
        int n = sat.size();
        int f = 1;
        vector<vector<int>>dp(501,vector<int>(501,INT_MIN));
        return solve(sat, n - 1, f,dp);
    }
};