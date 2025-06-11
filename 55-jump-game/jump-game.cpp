class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return true;
        if(nums[0]==0)return false;
        int curr=nums[0];
        for(int i=1;i<n;i++){
            if(i>curr)return false;
            if(curr>=n-1)return true;
            curr=max(curr,i+nums[i]);
        }
        return false;
        
    }
};