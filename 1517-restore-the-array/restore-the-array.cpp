class Solution {
public:
    int mod=1e9+7;
    int solve(string &s,int k,int ind,vector<int>&dp){
        int n=s.size();
        if(ind>=n)return 1;
        if(s[ind]=='0')return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=0;
        long long curr=0;
        for(int end=ind;end<n;end++){
            curr=curr*10+s[end]-'0';
            if(curr>k)break;
            ans=((ans%mod)+(solve(s,k,end+1,dp))%mod)%mod;
        }
        return dp[ind]=ans;
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        return solve(s,k,0,dp);
        
    }
};