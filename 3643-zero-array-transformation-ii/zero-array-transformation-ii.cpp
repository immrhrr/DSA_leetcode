class Solution {
public:


    bool check(vector<int>nums,int k,vector<vector<int>>&q){
        int n=nums.size();
        vector<int>diff(n,0);
        bool flag=true;
        for(int i=0;i<k;i++){
            int l=q[i][0];
            int r=q[i][1];
            int val=q[i][2];
            diff[l]+=val;
            if(r+1<n)
            diff[r+1]+=-val;
        }
        int cumsum=0;
        for(int i=0;i<n;i++){
            cumsum+=diff[i];
            if(nums[i]>cumsum){
                return false;
            }
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        int n=nums.size();
       
        int low=0;
        int high=q.size();
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
           if(check(nums,mid,q)){
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