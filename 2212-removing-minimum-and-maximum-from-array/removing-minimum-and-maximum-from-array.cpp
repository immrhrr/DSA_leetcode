class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1||n==2)return n;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        int min_ind=-1;
        int max_ind=-1;
        for(int i=0;i<n;i++){
                if(nums[i]==maxi){
                    max_ind=i;
                }
                if(nums[i]==mini){
                    min_ind=i;
                }
            } 
        
        int left=min(min_ind,max_ind);
        int right=max(min_ind,max_ind);
        //if they are at consecutive place then either form left or right side is possible
        
        int t1=right+1;
        int t2=n-left;
        int t3=left+1+n-right;
        return min({t1,t2,t3});
        

        
    }
};