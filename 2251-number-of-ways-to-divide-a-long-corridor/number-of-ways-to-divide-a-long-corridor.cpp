class Solution {
public:
    int numberOfWays(string s) {
        int n=s.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(s[i]=='S'){
                temp.push_back(i);
            }
        }
        if(temp.size()%2==1||temp.size()<2)return 0;
        int ans=1;
        int mod=1e9+7;
        for(int i=2;i<temp.size();i+=2){
            ans=((long long)ans*(temp[i]-temp[i-1]))%mod;
        }
        return ans;
    }
};