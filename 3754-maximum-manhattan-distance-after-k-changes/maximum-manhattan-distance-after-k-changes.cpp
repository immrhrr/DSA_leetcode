class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int east=0;
        int west=0;
        int north=0;
        int south=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N')north++;
            if(s[i]=='E')east++;
            if(s[i]=='W')west++;
            if(s[i]=='S')south++;
            int expected=i+1;
            int actual=abs(north-south)+abs(east-west);
            int extra=min(2*k,expected-actual);
            ans=max(ans,actual+extra);
        }
        return ans;
    }
};