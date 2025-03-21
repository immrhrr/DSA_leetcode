class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
         int maxi=0;
        int start=0;
        for(int len=1;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(len==1){
                    dp[i][j]=true;
                }
                if(len==2){
                    if(s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }
                else{
                    if(i+1<n&&j-1>=0&&dp[i+1][j-1]&&s[i]==s[j]){
                        dp[i][j]=true;
                    }
                }
                if(dp[i][j]&&j-i+1>maxi){
                    maxi=j-i+1;
                    start=i;
                }
            }
        }
        string ans=s.substr(start,maxi);
        return ans;
        
    }
};