class Solution {
public:
    bool check(string s1,string s2){
        int n1=s1.size();
        int n2=s2.size();
        if(n1-n2!=1){
            return false;
        }
        int i=0;int j=0;
        while(i<n1&&j<n2){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return (j==n2);
    }
    int solve(vector<string>&words,int prev,int ind,vector<vector<int>>&dp){
        int n=words.size();
        if(ind>=n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        int take=0;
        int notake=0;
        if(prev==-1||check(words[ind],words[prev])){
            take=1+solve(words,ind,ind+1,dp);
        }
        notake=solve(words,prev,ind+1,dp);
        return dp[ind][prev+1]=max(take,notake);
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](const string &a,const string&b){
            return a.size()<b.size();
        });
        int n=words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
       return solve(words,-1,0,dp);
    }
};