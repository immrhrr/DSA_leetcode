class Solution {
public:
    bool solve(int n,unordered_map<int,int>&mp){
        if(n<=0){
            return false;
        }
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
       
        for(int i=1;i*i<=n;i++){
            if(solve(n-i*i,mp)==0){
                mp[n]= 1;
                return true;
            }
        }
        mp[n]=0;
        return false;
    }
    bool winnerSquareGame(int n) {
        unordered_map<int,int>mp;
        
        return solve(n,mp);
    }
};