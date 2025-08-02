class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int maxi=0;
        int sum=0;
        unordered_map<int,int>mp;
        int i=0;
        int j=0;
        while(j<n){
            mp[nums[j]]++;
            maxi=max(maxi,mp[nums[j]]);
            sum++;
            while(sum-maxi>k){
                mp[nums[i]]--;
                maxi=max(maxi,mp[nums[i]]);
                i++;
                sum--;
            }
            ans=max(ans,maxi);
            j++;
        }
        return ans;
    }
};