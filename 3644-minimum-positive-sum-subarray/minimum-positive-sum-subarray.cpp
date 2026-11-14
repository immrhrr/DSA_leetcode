class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            for(int j=l;j<=r;j++){
                if(j+i>n)break;
                int curr=pref[j+i]-pref[i];
                if(curr>0){
                    ans=min(ans,curr);
                }
            }
        }
        if(ans==INT_MAX)
        return -1;
        return ans;
        
    }
};