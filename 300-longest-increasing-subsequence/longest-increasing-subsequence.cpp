class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        int ans=1;
        //length of lis ending at ith index
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    lis[i]=max(1+lis[j],lis[i]);
                }
                
                ans=max(ans,lis[i]);
            }
        }
        return ans;
    }
};