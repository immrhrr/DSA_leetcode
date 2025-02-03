class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int positive=1;
        int negative=1;
        int ans=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                positive++;
                ans=max(ans,positive);
            }
            else{
                positive=1;
                ans=max(ans,positive);
            }
             if(nums[i]<nums[i-1]){
             negative++;
                ans=max(ans,negative);
            }
            else{
              negative=1;
                ans=max(ans,negative);
            }
        }
        return ans;
    }
};