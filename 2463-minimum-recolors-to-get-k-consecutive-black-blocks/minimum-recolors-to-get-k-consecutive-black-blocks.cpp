class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        vector<int>pref(n,0);
        if(blocks[0]=='B'){
            pref[0]=1;
        }
        for(int i=1;i<n;i++){
            if(blocks[i]=='B'){
                pref[i]=pref[i-1]+1;
            }
            else{
                pref[i]=pref[i-1];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++){
            int j=i+k-1;
            int tot=j-i+1;
            if(i==0){
                ans=min(ans,tot-pref[j]);
            }
            else{
            int black=pref[j]-pref[i-1];
            int need=tot-black;
            ans=min(ans,need);
            }
        }
        return ans;
    }
};