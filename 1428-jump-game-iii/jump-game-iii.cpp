class Solution {
public:
    bool solve(vector<int>&arr,int ind,vector<int>&dp){
        int n=arr.size();
        if(arr[ind]==0)return true;
        if(dp[ind]!=-1)return dp[ind];
        dp[ind]=0;
        int left=ind-arr[ind];
        int right=ind+arr[ind];
        bool l=false,r=false;
        if(left>=0){
            if(solve(arr,left,dp)){
                
                l=true;
            }
        }
        if(right<n){
            if(solve(arr,right,dp)){
                return r=true;
            }
            
        }
        return dp[ind]= l||r;
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<int>dp(n,-1);
        return solve(arr,start,dp);
    }
};