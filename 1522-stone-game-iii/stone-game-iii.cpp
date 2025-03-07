class Solution {
public:
    int solve(vector<int>&stone,int i,unordered_map<int,int>&mp){
        int n=stone.size();
        if(i>=n){
            return 0;
        }
        if(mp.find(i)!=mp.end()){
            return mp[i];
        }
        int result=INT_MIN;
        result=max(result,stone[i]-solve(stone,i+1,mp));
        if(i+1<n){
            result=max(result,stone[i]+stone[i+1]-solve(stone,i+2,mp));
        }
        if(i+2<n){
            result=max(result,stone[i]+stone[i+1]+stone[i+2]-solve(stone,i+3,mp));
        }
        mp[i]=result;
        return mp[i];
    }
    string stoneGameIII(vector<int>& stone) {
       int n=stone.size();
       unordered_map<int,int>mp;
       int temp= solve(stone,0,mp);
       if(temp>0){
        return "Alice";
       }
       else if(temp==0){
        return "Tie";
       }
       else{
        return "Bob";
       }
        
    }
};