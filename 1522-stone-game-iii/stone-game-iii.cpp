class Solution {
public:
    string stoneGameIII(vector<int>& stone) {
       int n=stone.size();
      int next1=0;
      int next2=0;
      int next3=0;
       for(int i=n-1;i>=0;i--){
        int temp=INT_MIN;
        temp=max(temp,stone[i]-next1);
        if(i+2<=n){
             temp=max(temp,stone[i+1]+stone[i]-next2);
        }
         if(i+3<=n){
             temp=max(temp,stone[i+1]+stone[i]+stone[i+2]-next3);
        }
      next3=next2;
      next2=next1;
       next1=temp;
       }
       if(next1>0){
        return "Alice";
       }
       else if(next1==0){
        return "Tie";
       }
       else{
        return "Bob";
       } 
    }
};