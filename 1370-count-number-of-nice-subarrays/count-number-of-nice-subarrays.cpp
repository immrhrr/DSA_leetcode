class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int odd=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                odd++;
            }
            int need=odd-k;
            if(mp.find(need)!=mp.end()){
                ans+=mp[need];
            }
            mp[odd]++;
        }
        return ans;
        
    }
};