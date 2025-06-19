class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int cnt=1;
        int limit=nums[0]+k;
        for(int i=1;i<n;i++){
            if(nums[i]>limit){
                cnt++;
                limit=nums[i]+k;
            }
        }
        return cnt;  
    }
};