class Solution {
public:
    int solve(vector<int>&prices,int k,int ind,bool can_buy,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        if(k<=0||ind>=n)return 0;
        if(dp[ind][k][can_buy]!=-1e5)return dp[ind][k][can_buy];

        if(can_buy){
            int buy=0;
            int nobuy=0;
            buy=-prices[ind]+solve(prices,k,ind+1,false,dp);
            nobuy=solve(prices,k,ind+1,true,dp);
            return dp[ind][k][can_buy]= max(buy,nobuy);

        }
        else{
            int sell=0;
            int nosell=0;
            sell=prices[ind]+solve(prices,k-1,ind+1,true,dp);
            nosell=solve(prices,k,ind+1,false,dp);
            return  dp[ind][k][can_buy]=max(sell,nosell);

        }

    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1e5)));
        return solve(prices,k,0,true,dp);
    }
};