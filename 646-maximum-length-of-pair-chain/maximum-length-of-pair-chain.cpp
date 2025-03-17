class Solution {
public:
    int solve(vector<vector<int>>&pairs,int prev,int ind,vector<vector<int>>&dp){
        int n=pairs.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int take=0;
        int notake=0;
        if(prev==-1||pairs[prev][1]<pairs[ind][0]){
            take=1+solve(pairs,ind,ind+1,dp);
        }
        notake=solve(pairs,prev,ind+1,dp);
        return dp[ind][prev+1]= max(take,notake);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n=pairs.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(pairs,-1,0,dp);
        
    }
};