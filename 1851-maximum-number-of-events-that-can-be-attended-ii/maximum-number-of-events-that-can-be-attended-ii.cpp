class Solution {
public:
    int find(vector<vector<int>>&events,int limit){
        int ind=events.size();
        int low=0;
        int high=events.size()-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(events[mid][0]>limit){
                ind=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ind;
    }
    int solve(vector<vector<int>>&events,int rem,int ind,vector<vector<int>>&dp){
        int n=events.size();
        if(rem==0||ind>=n){
            return 0;
        }
        if(dp[rem][ind]!=-1)return dp[rem][ind];
        int take=0;
        int notake=0;
        int next=find(events,events[ind][1]);
            //take
            take=events[ind][2]+solve(events,rem-1,next,dp);
            //notake
            notake=0+solve(events,rem,ind+1,dp);
            return dp[rem][ind]= max(take,notake);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(),events.end());
        int n=events.size();
        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        return solve(events,k,0,dp);
        
    }
};