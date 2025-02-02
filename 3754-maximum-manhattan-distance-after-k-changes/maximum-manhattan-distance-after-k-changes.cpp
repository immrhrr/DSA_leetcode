class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        unordered_map<char,int>mp;
        mp['N']=0; mp['E']=0;mp['S']=0;mp['W']=0;
        int ans=0;
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s[i]=='N'){
                y++;
            }
             if(s[i]=='E'){
                x++;
            }
             if(s[i]=='S'){
                y--;
            }
             if(s[i]=='W'){
                x--;
            }
            mp[s[i]]++;
            int vn=min(mp['N'],mp['S']);
            int hn=min(mp['E'],mp['W']);
            int temp=abs(x)+abs(y);
            int bonus=vn+hn;
            bonus=(min(k,bonus));
            temp+=2*bonus;
            ans=max(ans,temp);
        }
        return ans;
    }
};