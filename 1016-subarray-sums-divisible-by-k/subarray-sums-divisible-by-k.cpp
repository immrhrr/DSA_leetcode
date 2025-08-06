class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
        int ans=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        while(j<n){
            sum+=nums[j];
            //int rem=abs(sum)%k;
            int rem = (sum % k + k) % k;

            if(mp.find(rem)!=mp.end()){
                ans+=mp[rem];
            }
            mp[rem]++;
            j++;
        }
        return ans;
    }
};