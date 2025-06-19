class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,1);//len of lis ending at index i
        vector<int>cnt(n,1);//count pf lis ending at index i
        int len=1;
        for(int curr=0;curr<n;curr++){
            for(int prev=0;prev<curr;prev++){
                if(nums[curr]>nums[prev]){
                    if(dp[prev]+1==dp[curr]){
                        cnt[curr]+=cnt[prev];
                    }
                    else if(dp[prev]+1>dp[curr]){
                        cnt[curr]=cnt[prev];
                        dp[curr]=1+dp[prev];
                    }
                }
            }
            if(dp[curr]>len){
                len=dp[curr];
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==len){
                res+=cnt[i];
            }
        }
        return res;
        
    }
};