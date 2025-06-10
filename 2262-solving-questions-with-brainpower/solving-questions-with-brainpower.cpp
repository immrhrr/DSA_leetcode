class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        vector<long long>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int point=q[i][0];
            int penalty=q[i][1]+1;
            long long take=point;
            long long skip=0;
            if(i+penalty<n){
                take+=dp[i+penalty];
            }
            if(i+1<n){
                skip=dp[i+1];
            }
            dp[i]=max(take,skip);  
        }
        return dp[0];
    }
};