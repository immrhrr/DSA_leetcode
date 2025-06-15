class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        priority_queue<pair<int,int>>maxi;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mini;
        int cnt_pos=0;
        int last_pos_ind=-1;
        int first_pos_ind=-1;
        bool flag=false;
        for(int i=m-1;i<n;i++){
           maxi.push({nums[i],i});
           mini.push({nums[i],i});
           if(!flag&&nums[i]>=0){
            first_pos_ind=i;
            flag=true;
           }
           if(nums[i]>=0){
            cnt_pos++;
            last_pos_ind=i;
           }
        }
        long long ans=-1*1e10;
        // if(cnt_pos<2||(last_pos_ind-first_pos_ind+1<m)){
        //     ans=-1;
        // }
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