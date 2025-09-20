class Solution {
public:
    int solve(int n,int curr,vector<int>&dp){
        if(curr==n){
            return 1;
        }
        if(curr>n){
            return 0;
        }
        if(dp[curr]!=-1)return dp[curr];
        int one=0;
        int two=0;
        one=solve(n,curr+1,dp);
        two=solve(n,curr+2,dp);
        return dp[curr]= one+two;
    }
    int climbStairs(int n) {
        vector<int>dp(50,-1);
        return solve(n,0,dp);
    }
};