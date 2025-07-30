class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=0;
        int curr=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxi){
                curr++;
            }
            else{
                ans=max(ans,curr);
                curr=0;
            }
        }
        ans=max(ans,curr);
        return ans;
    }
};