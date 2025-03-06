class Solution {
public:
    int solve(vector<int>&frq,int ind,vector<int>&dp){
        int n=frq.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take=0;
        int notake=0;
        take=frq[ind]+solve(frq,ind+2,dp);
        notake=solve(frq,ind+1,dp);
        dp[ind]=max(take,notake);
        return dp[ind];
    }
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>frq(1e4+1,0);
        vector<int>dp(1e4+1,-1);
        for(int i=0;i<n;i++){
            frq[nums[i]]+=nums[i];
        }
        return solve(frq,0,dp);
    }
};