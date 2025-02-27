class Solution {
public:
    int solve(int j,int k,unordered_map<int,int>&mp,vector<int>&arr){
        int temp=arr[k]-arr[j];
        if(mp.find(temp)!=mp.end()&&mp[temp]<j){
            return 1+solve(mp[temp],j,mp,arr);
        }
        return 2;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]=i;
        }
        int ans=0;
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                int len=solve(j,k,mp,arr);
                if(len>2){
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};