class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        sort(nums.begin(),nums.end());
        int i=0;int j=n-1;
        while(j>i){
            ans+=nums[j-1];
            j=j-2;
            i=i+1;
        }
        return ans;
        
    }
};