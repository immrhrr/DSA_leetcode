class Solution {
public:
    int func(int num){
        int sum=0;
        while(num>0){
            int digit=num%10;
            sum+=digit;
            num=num/10;
        }
        return sum;

    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>temp(82);
        for(int i=0;i<n;i++){
            int digit_sum=func(nums[i]);
            temp[digit_sum].push_back(nums[i]);
        }
        int ans=-1;
        for(int i=0;i<82;i++){
            int size=temp[i].size();
            if(size<=1){
                continue;
            }
            sort(temp[i].begin(),temp[i].end());
            ans=max(ans,temp[i][size-2]+temp[i][size-1]);
        }
        return ans;
    }
};