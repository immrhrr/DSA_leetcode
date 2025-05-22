class Solution {
public:
    bool check(vector<int>&nums,vector<vector<int>>&q,int k){
        int n=nums.size();
        vector<int>temp(n,0);
        for(int i=0;i<=k;i++){
            int l=q[i][0];
            int r=q[i][1]+1;
            int val=q[i][2];
            if(r<n){
                temp[r]+=(-val);
            }
            temp[l]+=val;
        }
        for(int i=1;i<n;i++){
            temp[i]=temp[i]+temp[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>temp[i])return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& q) {
        //min k such that by processing first k quesrries it becomes zero
        int n=nums.size();
        bool flag=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                flag=false;
                break;
            }
        }
        if(flag)return 0;
        int m=q.size();
        int low=0;
        int high=m-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(check(nums,q,mid)){
                high=mid-1;
                ans=mid+1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};