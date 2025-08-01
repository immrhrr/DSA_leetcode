class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
          int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            //canbuy
            dp[i][0]=max(-prices[i]+dp[i+1][1],dp[i+1][0]);
            //cansell
            dp[i][1]=max(prices[i]-fee+dp[i+1][0],dp[i+1][1]);
        }
        return dp[0][0];
        
    }
};