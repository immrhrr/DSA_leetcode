class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int pref=1;
        int suff=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            pref=pref*nums[i];
            suff=suff*nums[n-i-1];
            
            ans=max({ans,pref,suff});
            if(nums[i]==0){
                pref=1;
            }
             if(nums[n-i-1]==0){
                suff=1;
            }
        }
        return ans;
        
    }
};