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
        if(n==2)return min(cost[0],cost[1]);
        for(int i=2;i<n;i++){
            cost[i]=cost[i]+min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};