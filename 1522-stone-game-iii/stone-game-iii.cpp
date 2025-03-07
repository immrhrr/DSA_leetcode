class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
       int n=stone.size();
       vector<int>dp(n+1,0);
       for(int i=n-1;i>=0;i--){
        int temp=INT_MIN;
        temp=max(temp,stone[i]-dp[i+1]);
        if(i+2<=n){
             temp=max(temp,stone[i+1]+stone[i]-dp[i+2]);
        }
         if(i+3<=n){
             temp=max(temp,stone[i+1]+stone[i]+stone[i+2]-dp[i+3]);
        }
        dp[i]=temp;
       }
       if(dp[0]>0){
        return "Alice";
       }
       else if(dp[0]==0){
        return "Tie";
       }
       else{
        return "Bob";
       } 
    }
};