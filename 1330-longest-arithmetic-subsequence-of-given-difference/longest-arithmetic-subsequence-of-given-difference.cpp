class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int ans=1;
        for(int i=0;i<n;i++){
            int need=arr[i]-d;
            if(mp.find(need)==mp.end()){
                mp[arr[i]]=1;
            }
            else{
                mp[arr[i]]=1+mp[need];
                ans=max(ans,mp[arr[i]]);
            }
        }
        return ans;
        
    }
};