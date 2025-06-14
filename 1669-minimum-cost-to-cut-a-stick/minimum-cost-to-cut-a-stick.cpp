class Solution {
public:
    int solve(vector<int>&cuts,int l,int r,vector<vector<int>>&dp){
        if(r-l<2)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        int ans=INT_MAX;
        for(int ind=l+1;ind<=r-1;ind++){
            int temp=(cuts[r]-cuts[l])+solve(cuts,l,ind,dp)+solve(cuts,ind,r,dp);
            ans=min(ans,temp);
        }
        return dp[l][r]= ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,-1));
        return solve(cuts,0,cuts.size()-1,dp);
        
    }
};