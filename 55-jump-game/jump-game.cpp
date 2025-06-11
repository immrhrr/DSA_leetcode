class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int curr=0;
        for(int i=0;i<n;i++){
            if(i>curr)return false;
            if(curr>=n-1)return true;
            curr=max(curr,i+nums[i]);
        }
        return false;
        
    }
};