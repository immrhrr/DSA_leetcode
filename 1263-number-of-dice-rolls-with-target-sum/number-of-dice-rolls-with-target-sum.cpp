class Solution {
public:
     int mod=1e9+7;
     int solve(int m,int n,int x,int sum,vector<vector<int>>&dp){
        if(n==0){
            return sum==x ? 1 : 0;
        }
        if(dp[n][sum]!=-1)return dp[n][sum];
        int ways=0;
        for(int i=1;i<=m;i++){
            if(sum+n>x||sum+m*n<x){
                continue;
            }
            if(sum+i<=x){
                ways=(ways+(solve(m,n-1,x,sum+i,dp))%mod)%mod;
                
            }
        }
        return dp[n][sum]= ways;
    }
    int numRollsToTarget(int n, int k, int target) {
         vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(k,n,target,0,dp);
    }
};