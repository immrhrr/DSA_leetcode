class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int need=st.size();
        int i=0;int j=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            while(mp.size()==need){
                ans+=n-j;
                mp[nums[i]]--;
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
        
    }
};