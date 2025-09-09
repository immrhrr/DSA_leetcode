class Solution {
public:
    int mod=1e9+7;
    vector<int>dp;
    int solve(int d,int delay,int forget){
        if(d==1)return 1;
        if(dp[d]!=-1)return dp[d];
        int res=0;
        for(int prev=d-forget+1;prev<=d-delay;prev++){
            if(prev>0){
                res=(res+solve(prev,delay,forget)%mod)%mod;

            }
        }
        return dp[d]= res;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        dp.resize(n+1,-1);
        int tot=0;
        for(int d=n-forget+1;d<=n;d++){
            if(d>0)
            tot=(tot+solve(d,delay,forget)%mod)%mod;
        }
        return tot;
    }
};