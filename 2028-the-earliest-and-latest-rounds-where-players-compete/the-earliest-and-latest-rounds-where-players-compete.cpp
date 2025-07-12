class Solution {
public:
    int N=0;
    int f=0;
    int s=0;
    int maxi=0;
    int mini=10;
    void solve(int mask,int round,int i,int j){
        //round over
        if(i>=j){
          solve(mask,round+1,0,N);
        }
        //ith dead hai
        else if((mask&(1<<i))==0){
            solve(mask,round,i+1,j);
        }
        //jth dead hai
        else if((mask&(1<<j))==0){
            solve(mask,round,i,j-1);
        }
        //mil gya
        else if(i==f&&j==s){
            maxi=max(maxi,round);
            mini=min(mini,round);
        }
        //ith amar hai
        else if(i==f||i==s){
            //jth ko unset kro
            solve(mask&~(1<<j),round,i+1,j-1);
        }
        //jth amar hai
        else if(j==f||j==s){
            //ith ko unset kro
            solve(mask&~(1<<i),round,i+1,j-1);
        }
        //anyone can die
        else{
            solve(mask&~(1<<j),round,i+1,j-1);
            solve(mask&~(1<<i),round,i+1,j-1);
        }
    }
    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        N=n-1;
        f=firstPlayer-1;
        s=secondPlayer-1;
        int mask=(1<<n)-1;
        solve(mask,1,0,n-1);
        return {mini,maxi};
    }
};