class Solution {
public:
    void solve(vector<int>&cookies,int k,vector<int>temp,int ind,int&ans){
        int n=cookies.size();
        if(ind>=n){
            int maxi=INT_MIN;
            for(int i=0;i<k;i++){
                maxi=max(maxi,temp[i]);
            }
            ans=min(ans,maxi);
            return;
        }
        for(int op=0;op<k;op++){
            temp[op]+=cookies[ind];
            if(temp[op]<=ans){
                solve(cookies,k,temp,ind+1,ans);
            }
            temp[op]-=cookies[ind];
            if(temp[op] == 0) break;
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>temp(k,0);
        int ans=INT_MAX;
        solve(cookies,k,temp,0,ans);
        return ans;
    }
};