class Solution {
public:
    int solve(vector<int>&prices,int ind,bool can_buy,vector<vector<int>>&dp){
        int n=prices.size();
        if(ind>=n)return 0;
        if(dp[ind][can_buy]!=-1)return dp[ind][can_buy];
        int buy=0;
        int nobuy=0;
        int sell=0;
        int nosell=0;
        if(can_buy){
            //buy
            buy=-prices[ind]+solve(prices,ind+1,false,dp);
            //nobuy
            nobuy=0+solve(prices,ind+1,true,dp);
        }
        
        else{
            sell=prices[ind]+solve(prices,ind+2,true,dp);
            nosell=solve(prices,ind+1,false,dp);

        }
        return dp[ind][can_buy]= max({buy,nobuy,sell,nosell});
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,0,true,dp);
        
    }
};