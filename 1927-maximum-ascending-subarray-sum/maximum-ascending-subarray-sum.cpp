class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        int temp=nums[0];
        int prev=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>prev){
                temp+=nums[i];
            }
            else{
                temp=nums[i];
            }
            prev=nums[i];
            ans=max(ans,temp);
        }
        return ans;
    }
};