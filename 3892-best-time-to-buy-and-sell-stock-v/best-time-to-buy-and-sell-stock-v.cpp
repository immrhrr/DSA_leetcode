class Solution {
public:
    long long solve(vector<int>&prices,int k,int state,int ind,vector<vector<vector<long long>>>&dp){
        int n=prices.size();
        if(ind>=n){
            //return 0;
           return  state == 0 ? 0 : LLONG_MIN;
        }
        if(k==0){
            return 0;
            //return state == 0 ? 0 : LLONG_MIN;
        }
        if(dp[k][state][ind]!=LLONG_MAX){
            return dp[k][state][ind];
        }
        long long ans=0;
        if(state==0){
            long long buy = solve(prices,k,1,ind+1,dp);
            long long sell = solve(prices,k,2,ind+1,dp);
            long long skip = solve(prices,k,0,ind+1,dp);
            long long net_buy = (buy==LLONG_MIN) ? LLONG_MIN : buy-prices[ind];
            long long net_sell = (sell==LLONG_MIN) ? LLONG_MIN : sell + prices[ind];
            ans= max({skip,net_buy,net_sell});
        }
        else if(state==1){
            long long sell = solve(prices,k-1,0,ind+1,dp);
            long long skip = solve(prices,k,1,ind+1,dp);
            long long net_sell = (sell==LLONG_MIN) ? LLONG_MIN : sell + prices[ind];
            ans=max({skip,net_sell});
        }
         else {
            long long buy = solve(prices,k-1,0,ind+1,dp);
            long long skip = solve(prices,k,2,ind+1,dp);
            long long net_buy = (buy==LLONG_MIN) ? LLONG_MIN : buy - prices[ind];
            ans=max({skip,net_buy});
        }
        return dp[k][state][ind]=ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int state=0;
        int ind=0;
        int n=prices.size();
        vector<vector<vector<long long>>>dp(k+1,vector<vector<long long>>(4,vector<long long>(n+1,LLONG_MAX)));
        return solve(prices,k,state,ind,dp);
        
    }
};