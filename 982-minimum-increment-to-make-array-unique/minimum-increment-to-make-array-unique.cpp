class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<=prev){
                prev++;
                ans+=prev-nums[i];
            }
            else{
                prev=nums[i];
            }

        }
        return ans;
    }
};