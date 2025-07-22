class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int gola_index = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i] > nums[i - 1]) {
                gola_index = i-1;
                break;
            }
        }
        if(gola_index==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int swap_index=gola_index;
        for(int i=n-1;i>gola_index;i--){
            if(nums[i]>nums[gola_index]){
                swap_index=i;
                break;
            }
        }
        swap(nums[gola_index],nums[swap_index]);
        reverse(nums.begin()+gola_index+1,nums.end());
        return;
    }
};