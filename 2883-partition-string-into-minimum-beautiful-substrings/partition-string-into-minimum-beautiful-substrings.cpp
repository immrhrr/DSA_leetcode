class Solution {
public:
    bool check(string&s,int start,int end){
         unordered_set<string> st = {
            "1", "101", "11001", "1111101", "1001110001", 
            "110000110101", "11110100001001"
        };
        string temp=s.substr(start,end-start+1);
        if(st.find(temp)==st.end())return false;
        return true;
    }
    int solve(string&s,int ind,vector<int>&dp){
        int n=s.size();
        if(ind>=n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int ans=100;
        int temp=0;
        for(int i=ind;i<n;i++){
            if(check(s,ind,i)){
                int temp=solve(s,i+1,dp);
                if(temp!=100){
                    ans=min(ans,1+temp);
                }
            }
        }
        return dp[ind]=ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        int ans=solve(s,0,dp);
        if(ans>=100)return -1;
        return ans;
    }
};