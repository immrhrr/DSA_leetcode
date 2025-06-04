class Solution {
public:
    int solve(vector<int>&cost,int ind,vector<int>&dp){
        int n=cost.size();
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int op1=0;
        int op2=0;
        op1=cost[ind]+solve(cost,ind+1,dp);
        op2=cost[ind]+solve(cost,ind+2,dp);
        return dp[ind]=min(op1,op2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp1(n+1,-1);
        int op1=solve(cost,0,dp1);
        vector<int>dp2(n+1,-1);
        int op2=solve(cost,1,dp2);

        return min(op1,op2);
        
    }
};