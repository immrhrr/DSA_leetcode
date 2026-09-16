class Solution {
public:
    int M=1e9+7;
    
    int numberOfSets(int n, int K) {
        vector<vector<int>>dp(1001,vector<int>(1001,0));
        //k,i
        for(int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for(int k=1;k<=K;k++){
            vector<int>arr(n+1,0);
            for(int x=n-1;x>=0;x--){
                arr[x]=(arr[x+1]+dp[k-1][x])%M;
            }
            for(int i=n-1;i>=0;i--){
                int take=0;
                int skip=(dp[k][i+1])%M;
                take=arr[i+1];
                
                dp[k][i]=(take+skip)%M;
            }
        }
        return dp[K][0];
    }
};