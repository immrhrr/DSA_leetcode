class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[n-1];
        int ans=INT_MIN;
        for(int i=n-2;i>=0;i--){
            if(maxi>nums[i]){
            ans=max(ans,maxi-nums[i]);
            }
            maxi=max(maxi,nums[i]); 
        }

        if(ans<=0){
            return -1;
        }
        return ans;
    }
};