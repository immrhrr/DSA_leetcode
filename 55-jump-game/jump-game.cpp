class Solution {
public:
    bool solve(vector<int>&nums,int ind,vector<int>&dp){
        int n=nums.size();
        if(ind>=n-1)return true;
        if(dp[ind]!=-1)return dp[ind];
        int m=nums[ind];
        bool check=false;
        for(int i=0;i<m;i++){
            check=solve(nums,ind+i+1,dp);
            if(check)break;
        }
       return dp[ind]=check;
    }
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,0,dp);
    }
};