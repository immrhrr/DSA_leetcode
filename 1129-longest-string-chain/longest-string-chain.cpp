class Solution {
public:
    static bool lambd(const string&s1,const string&s2){
        return s1.size()<s2.size();
    }
    bool check(vector<string>&words,int ind,int prev,vector<vector<int>>&dp2){
        if(dp2[ind][prev]!=-1)return dp2[ind][prev];
        string &s1=words[ind];
        string &s2=words[prev];
        int n1=s1.size();
        int n2=s2.size();
        if(n1-n2!=1)return dp2[ind][prev]=false;
        int i=0;
        int j=0;
        int cnt=0;
        //s2 chhota hai
        //s1 bada hai
        while(i<n1&&j<n2){
            if(s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
                cnt++;
            }
            if(cnt>1)return dp2[ind][prev]=false;
        }
        return dp2[ind][prev]=true;
    }
    int solve(vector<string>&words,int ind,int prev_ind,vector<vector<int>>&dp,vector<vector<int>>&dp2){
        int n=words.size();
        if(ind>=n)return 0;
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        int take=0;
        int notake=0;
        if(prev_ind==-1||check( words ,ind, prev_ind,dp2)){
            take=1+solve(words,ind+1,ind,dp,dp2);
        }
        notake=solve(words,ind+1,prev_ind,dp,dp2);
        return dp[ind][prev_ind+1]=max(take,notake);
    }
    int longestStrChain(vector<string>& words) {
        //first sort the words according to their length
        sort(words.begin(),words.end(),lambd);
        int n=words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        vector<vector<int>>dp2(n+1,vector<int>(n+1,-1));
        return solve(words,0,-1,dp,dp2);

        
    }
};