class Solution {
public:
    bool check(vector<int>&nums,int ind,long long curr,long long target){
        int n=nums.size();
        if(curr==target)return true;

        if(ind>=n||curr>target)return false;

        bool take=false;
        bool notake=false;
        take=check(nums,ind+1,curr*nums[ind],target);
        if(take)return true;
        notake=check(nums,ind+1,curr,target);
        return take||notake;

    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n=nums.size();
        long double temp=1;
        for(int i=0;i<n;i++){
            temp=temp*nums[i];
        }
        if(temp!=(long double)target*target)return false;
        return check(nums,0,1,target);
    }
};