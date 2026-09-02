class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        return true;
        //odd-odd=even
        //even-even=even
        //odd-even=odd
        //even-odd=odd
        int n=nums.size();
        bool all_odd=true;
        bool all_even=true;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                all_even=false;
            }
            else{
                all_odd=false;
            }
        }
        return all_odd||all_even;
    }
};