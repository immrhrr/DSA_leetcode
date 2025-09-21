class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%2==1)return false;
        int m=tot/2;
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        //row matlab index
        //col matlab sum
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                bool notake=dp[i-1][j];
                bool take=false;
                if(j-nums[i-1]>=0&&dp[i-1][j-nums[i-1]]){
                    take=true;
                }
                dp[i][j]=take|notake;
            }
        }
        return dp[n][m];
    }
};