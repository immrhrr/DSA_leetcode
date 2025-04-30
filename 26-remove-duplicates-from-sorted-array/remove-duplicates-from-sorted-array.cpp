class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[ind]){
                ind++;
                nums[ind]=nums[i];
            }
        }
        return ind+1;
    }
};