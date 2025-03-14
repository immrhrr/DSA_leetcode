class Solution {
public:
    int solve(vector<pair<int,int>>&temp,int ind,vector<vector<int>>&dp,int last){
        if(ind<0){
            return 0;
        }
        if(dp[ind][last]!=-1){
            return dp[ind][last];
        }
        int take=0;
        int notake=0;
        int p_score=1e6+1;
        int p_age=10001;
        if(last!=temp.size())
        {
             p_score=temp[last].second;p_age=temp[last].first;

        }
       
        if(temp[ind].second<=p_score  || temp[ind].first==p_age){
            take=temp[ind].second+solve(temp,ind-1,dp,ind);
        }
        notake=0+solve(temp,ind-1,dp,last);
        return dp[ind][last]=max(take,notake);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<pair<int,int>>temp(n);
        for(int i=0;i<n;i++){
            temp[i]={ages[i],scores[i]};
        }
        sort(temp.begin(),temp.end());
        //age,score
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(temp,n-1,dp,n);
    }
};