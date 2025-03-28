class Solution {
public:
    bool check(vector<int>&nums,int k,int limit){
        int n=nums.size();
        int temp=0;
        int cnt=1;
        for(int i=0;i<n;i++){
            if(nums[i]>limit){
                return false;
            }
            temp+=nums[i];
            if(temp>limit){
                cnt++;
                temp=nums[i];
            }  
        }
        
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int high=0;
         int low=INT_MAX;
        for(auto num:nums){
            high+=num;
            low=min(low,num);
        }
       
        int ans=INT_MAX;
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