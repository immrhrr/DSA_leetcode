class Solution {
public:
    bool check(vector<int>&nums,int k,int limit){
        int n=nums.size();
        int cnt=0;
        int prev=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<=limit&&(prev==-1||i-prev!=1)){
                cnt++;
                prev=i;
            }
        }
        return cnt>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int low=INT_MAX;
        int high=INT_MIN;
        for(auto it:nums){
            low=min(low,it);
            high=max(high,it);
        }
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};