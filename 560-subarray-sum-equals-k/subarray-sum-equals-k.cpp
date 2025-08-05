class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            int need=curr-k;
            if(mp.find(need)!=mp.end()){
                cnt+=mp[need];
            }
            mp[curr]++;
        }
        return cnt;
    }
};