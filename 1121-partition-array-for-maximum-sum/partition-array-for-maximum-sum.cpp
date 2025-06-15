class Solution {
public:
    int solve(vector<int>&arr,int k,int l,int r,vector<int>&dp){
        int n=arr.size();
        if(dp[l]!=-1)return dp[l];
        if(l>=n)return 0;
        int ans=INT_MIN;
        int temp=0;
        int maxi=INT_MIN;
        for(int i=l;i<=min(l+k-1,r);i++){
            maxi=max(maxi,arr[i]);
            temp=maxi*(i-l+1)+solve(arr,k,i+1,r,dp);
            ans=max(ans,temp);
        }
        return dp[l]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(arr,k,0,n-1,dp);
        
    }
};