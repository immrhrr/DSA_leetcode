class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n=nums.size();
        
        //meat[i]=a*constant+b
        //a=nums[i];
        //b=nums[nums[i]];

        for(int i=0;i<n;i++){
            nums[i]=nums[i]+(nums[nums[i]]%1001)*1001;
        }
        for(int i=0;i<n;i++){
            nums[i]=nums[i]/1001;
        }
        return nums;
        
    }
};