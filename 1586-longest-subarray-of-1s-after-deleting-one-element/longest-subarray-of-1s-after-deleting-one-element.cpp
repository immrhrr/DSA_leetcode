class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        int j=0;
        int zero=0;
        while(j<n){
            if(nums[j]==0){
                zero++;
            }
            while(zero>1){
                if(nums[i]==0){
                    zero--;
                }
                i++;
            }
            ans=max(ans,j-i);
            j++;
        }
        return ans;
    }
};