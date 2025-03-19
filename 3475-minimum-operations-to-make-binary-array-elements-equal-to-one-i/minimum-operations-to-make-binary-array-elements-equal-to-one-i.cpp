class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==1){
                continue;
            }
            cnt++;
            for(int j=i;j<i+3;j++){
                nums[j]=!nums[j];
            }
        }
        if(nums[n-1]==1&&nums[n-2]==1){
            return cnt;
        }
        return -1;
        
    }
};