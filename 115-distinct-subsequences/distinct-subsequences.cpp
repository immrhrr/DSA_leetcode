class Solution {
public:
    vector<vector<int>>dp;
    int solve(string&s,string&t,int i,int j){
        if(j<0)return 1;
        if(i<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take=0;
        int notake=0;
        if(s[i]==t[j]){
            take=solve(s,t,i-1,j-1);
        }
        notake=solve(s,t,i-1,j);
        return dp[i][j]= take+notake;
        
    }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(s,t,n-1,m-1);
        

        
    }
};