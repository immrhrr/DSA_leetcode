class Solution {
public:
    
    int sortPermutation(vector<int>& nums) {
        int n=nums.size();
        int temp=-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                if(temp==-1){
                    temp=nums[i];
                }
                else{
                    temp=temp&nums[i];
                }
            }
        }
        if(temp==-1)return 0;
        return temp;
    }
};