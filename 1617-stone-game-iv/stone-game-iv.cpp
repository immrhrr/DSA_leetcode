class Solution {
public:
    bool solve(int n,vector<int>&dp){
        if(n<=0){
            return false;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        for(int i=1;i*i<=n;i++){
            if(solve(n-i*i,dp)==0){
                dp[n]= true;
                return true;
            }
        }
        dp[n]=false;
        return false;
    }
    bool winnerSquareGame(int n) {
        vector<int>dp(1e5+1,-1);
        return solve(n,dp);
    }
};