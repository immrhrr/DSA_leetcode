class Solution {
public:
    unordered_map<int,int>mp;
    bool solve(int n){
        if(n<=0){
            return false;
        }
        if(mp.find(n)!=mp.end()){
            return mp[n];
        }
       
        for(int i=1;i*i<=n;i++){
            if(solve(n-i*i)==0){
                mp[n]= 1;
                return true;
            }
        }
        mp[n]=0;
        return false;
    }
    bool winnerSquareGame(int n) {
        
        
        return solve(n);
    }
};