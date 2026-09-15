class Solution {
public:
    bool check(string &s,int i,int j){
        while(j>=i){
            if(s[i]!=s[j])return false;
            i++;j--;
        }
        return true;
    }
    int solve(string &s,int k,int i,int j,vector<vector<int>>&dp){
        int n=s.size();
        if(i>=n||j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(check(s,i,j)){
            int take=1+solve(s,k,j+1,j+k,dp);
            int grow=solve(s,k,i,j+1,dp);
            int slide=solve(s,k,i+1,j+1,dp);
            return dp[i][j]= max({take,slide,grow});
        }
        else{
            int grow=solve(s,k,i,j+1,dp);
            int slide=solve(s,k,i+1,j+1,dp);
            return dp[i][j]= max({slide,grow});
        }
    }
    int maxPalindromes(string s, int k) {
        if(k==1)return s.size();
        vector<vector<int>>dp(2000,vector<int>(2000,-1));
        return solve(s,k,0,k-1,dp);
        
    }
};