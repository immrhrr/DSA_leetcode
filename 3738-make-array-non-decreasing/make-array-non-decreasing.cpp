class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
       int last=-1;
       int cnt=0;
       for(int i=0;i<n;i++){
        if(nums[i]>=last){
            last=nums[i];
            cnt++;
        }
       }
       return cnt;
    }
};