class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            int need1=nums[i]-1;
            if(mp.find(need1)!=mp.end()){
                int temp1=mp[nums[i]]+mp[need1];
                ans=max(ans,temp1);
            }
            int need2=nums[i]+1;
            if(mp.find(need2)!=mp.end()){
                int temp2=mp[nums[i]]+mp[need2];
                ans=max(ans,temp2);
            }
        }
        return ans;
    }
};