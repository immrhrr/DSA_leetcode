class Solution {
public:
    
    int solve(vector<int>&rods,int idx,int diff,vector<vector<int>>&dp){
        if(idx<0){
            if(diff==0){
                return 0;
            }
            return INT_MIN;
        }
        if(dp[idx][diff+5000]!=-1){
            return dp[idx][diff+5000];
        }
        int op1=rods[idx]+solve(rods,idx-1,diff+rods[idx],dp);
        int op2=rods[idx]+solve(rods,idx-1,diff-rods[idx],dp);
        int op3=solve(rods,idx-1,diff,dp);
        return dp[idx][diff+5000]=max({op1,op2,op3});
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int diff=0;
        int idx=n-1;
        vector<vector<int>>dp(21,vector<int>(10001,-1));
       
        return solve(rods,idx,diff,dp)/2;
        
    }
};