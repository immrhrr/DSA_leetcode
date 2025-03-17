class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,1);
        vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    if(lis[j]+1==lis[i]){
                        ans[i]+=ans[j];
                    }
                    else if(lis[j]+1>lis[i]){
                        ans[i]=ans[j];
                        lis[i]=lis[j]+1;
                    }
                }
            }
        }
        int maxi=1;
        for(int i=0;i<n;i++){
            maxi=max(maxi,lis[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(lis[i]==maxi){
                cnt+=ans[i];
            }
        }
        return cnt;
        
    }
};