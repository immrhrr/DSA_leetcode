class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(nums[n-1]<=0){
            return 1;
        }
        int ans=1;
        int i=0;
        while(i<n){
            if(nums[i]>ans){
                return ans;
            }
            if(nums[i]==ans){
                ans++;
            }
           i++;
        }
        
        return nums[n-1]+1;
        
    }
};