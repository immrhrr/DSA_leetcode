class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int l=1;l<=n;l++){
            for(int start=0;start<=n-l;start++){
                int end=start+l-1;
                if(l==1){
                    dp[start][end]=true;
                    ans++;
                }
                else if(l==2){
                    if(s[start]==s[end]){
                        dp[start][end]=true;
                        ans++;
                    }
                }
                else{
                    if(dp[start+1][end-1]&&s[start]==s[end]){
                        dp[start][end]=true;
                         ans++;
                    }
                }
            }
        }
        return ans;
        
    }
};