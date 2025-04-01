class Solution {
public:
    long long solve(vector<vector<int>>&questions,int ind,vector<long long>&dp){
        int n=questions.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        long long take=0;
        long long skip=0;
        take=questions[ind][0]+solve(questions,ind+questions[ind][1]+1,dp);
        skip=0+solve(questions,ind+1,dp);
        return dp[ind]= max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,-1);
        return solve(questions,0,dp);
        



        
    }
};