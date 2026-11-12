class Solution {
public:
    bool solve(int i,int j,vector<int>&nums){
        if(nums[i]==nums[j])return false;
        bool increasing=true;
        for(int ind=i+1;ind<=j;ind++){
            if(nums[ind]<=nums[ind-1]){
                increasing =false;
                break;
            }
        }
        if(increasing)return true;
        
        bool decreasing =true;
        for(int ind=i+1;ind<=j;ind++){
            if(nums[ind]>=nums[ind-1]){
                decreasing =false;
                break;
            }
        }

        return increasing || decreasing ;

    }
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool flag=solve(i,j,nums);
                if(flag){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};