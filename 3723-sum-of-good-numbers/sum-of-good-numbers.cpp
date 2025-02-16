class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int l=i-k;
            int r=i+k;
            if(l>=0&&nums[l]>=nums[i])
            {
                continue;
            }
            if(r<n&&nums[r]>=nums[i]){
                continue;
            }
            ans+=nums[i];
        }
        return ans;
    }
};