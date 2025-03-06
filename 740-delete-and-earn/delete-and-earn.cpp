class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>frq(1e4+1,0);
        vector<int>dp(1e4+1,0);
        for(int i=0;i<n;i++){
            frq[nums[i]]+=nums[i];
        }
        // int prev=0;
        // int curr=0;
        dp[1]=frq[1];
        for(int i=2;i<frq.size();i++){
            dp[i]=max(dp[i-1],dp[i-2]+frq[i]);
        }
        return dp[frq.size()-1];
    }
};