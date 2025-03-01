class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        int n=nums.size();
        int index=0;
        vector<int>ans(n,0);
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                nums[i]=nums[i]*2;
                nums[i+1]=0;
            }
            if(nums[i]!=0){
                ans[index++]=nums[i];
            }
        }
       if(nums[n-1]!=0){
        ans[index]=nums[n-1];
       }
        return ans;
       
    }
};