class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        if(n<3){
               return n;
        }
        int ans=2;
        vector<vector<int>>dp(n,vector<int>(1001,0));
        //ending at index i with diff as d
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int d=nums[i]-nums[j];
                int newd=d+500;
               dp[i][newd]=max(2,1+dp[j][newd]);
               ans=max(ans,dp[i][newd]);
            }
        }
        return ans;
    }
};