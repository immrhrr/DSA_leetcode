class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX;
        bool all_even=true;
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            if(nums[i]%2==1){
                all_even=false;
            }
        }
        if(mini%2==1)return true;
        return all_even;
        

    }
};