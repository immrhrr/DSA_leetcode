class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
        int mask=0;
        int ans=1;
        while(j<n){
            while((mask&nums[j])!=0){
                mask=(mask^nums[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            mask=mask|nums[j];
            j++;

        }
        return ans;
        
    }
};