class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int n=b1.size();
        unordered_map<int,int>mp;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mp[b1[i]]++;
            mp[b2[i]]--;
            mini=min({mini,b1[i],b2[i]});
        }
        long long ans=0;
        vector<int>arr;
        for(auto it:mp){
            int ele=it.first;
            int frq=abs(it.second);
            if(frq==0)continue;
            if(frq%2==1)return -1;
            for(int i=1;i<=frq/2;i++){
                arr.push_back(ele);
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()/2;i++){
            ans+=min(arr[i],2*mini);
        }
        return ans;
    }
};