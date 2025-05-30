class Solution {
public:
    int solve(vector<int>&coins,int amount,int ind,vector<vector<int>>&dp){
        int n=coins.size();

        if(amount<0||ind>=n)return 0;
        if(amount==0)return 1;
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int take=0;
        int notake=0;
        if(coins[ind]<=amount){
            take=solve(coins,amount-coins[ind],ind,dp);
        }
        notake=solve(coins,amount,ind+1,dp);
        return dp[ind][amount] =take+notake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(301,vector<int>(5001,-1));
        return solve(coins,amount,0,dp);
        
    }
};