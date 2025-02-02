class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int ans=0;
        int north=0;int east=0;int south=0;int west=0;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                y++;
                north++;
            }
             if(s[i]=='E'){
                x++;
                east++;
            }
             if(s[i]=='S'){
                y--;
                south++;
            }
             if(s[i]=='W'){
                x--;
                west++;
            }
            
            int vn=min(north,south);
            int hn=min(east,west);
            int temp=abs(x)+abs(y);
            int bonus=vn+hn;
            bonus=(min(k,bonus));
            temp+=2*bonus;
            ans=max(ans,temp);
        }
        return ans;
    }
};