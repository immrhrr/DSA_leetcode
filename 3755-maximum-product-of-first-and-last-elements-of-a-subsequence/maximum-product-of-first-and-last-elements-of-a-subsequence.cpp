class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        priority_queue<pair<int,int>>maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
        for(int i=m-1;i<n;i++){
           maxi.push({nums[i],i});
           mini.push({nums[i],i});
        }
        long long ans=-1*1e10;
        for(int i=0;i<=n-m;i++){
           int j=maxi.top().second;
           while(!maxi.empty()&&j-i+1<m){
            maxi.pop();
            j=maxi.top().second;
           }
           long long big=maxi.top().first;

           j=mini.top().second;
           while(!mini.empty()&&j-i+1<m){
            mini.pop();
            j=mini.top().second;
           }
           long long small=mini.top().first;
           ans=max({ans,nums[i]*big,nums[i]*small});
        }
        return ans;
        
    }
};