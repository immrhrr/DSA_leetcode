class Solution {
public:
    vector<vector<double>>dp;
    vector<pair<int,int>>serves={{100,0},{75,25},{50,50},{25,75}};
    double solve(double a,double b){
        if(a<=0&&b<=0){
            return 0.5;
        }
        if(a<=0){
            return 1.0;
        }
        if(b<=0){
            return 0;
        }
        if(dp[a][b]!=-1)return dp[a][b];
        double p=0.0;
        for(int i=0;i<serves.size();i++){
            int a_taken=serves[i].first;
            int b_taken=serves[i].second;
            p+=solve(a-a_taken,b-b_taken);
        }
        return dp[a][b]= 0.25*p;
    }
    double soupServings(int n) {
        if(n>4275)return 1;
        dp.resize(n+1,vector<double>(n+1,-1.0));
        return solve(n,n);
    }
};