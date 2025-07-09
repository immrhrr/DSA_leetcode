class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt_zero=0;
        int ans=0;
        while(j<n){
            if(nums[j]==0){
                cnt_zero++;
            }
            while(i<j&&cnt_zero>k){
                if(nums[i]==0){
                    cnt_zero--;
                }
                i++;
            }
            if(cnt_zero!=j-i+1){
                ans=max(ans,j-i+1);
            }
            else{
                ans=max(ans,k);
            }
            j++;
        }
        return ans;
        
    }
};