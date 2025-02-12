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
        vector<vector<int>>temp(82,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            int digit_sum=func(nums[i]);
           if(temp[digit_sum][1]==-1){
            temp[digit_sum][1]=nums[i];
           }
           else if(temp[digit_sum][0]==-1){
            temp[digit_sum][0]=nums[i];
           }
           else{
            int smaller=min(temp[digit_sum][0],temp[digit_sum][1]);
            int bigger=max(temp[digit_sum][0],temp[digit_sum][1]);
            //no need to update
            if(nums[i]<=smaller){
                continue;
            }
            //need to update
            //smaller of these two will be replaced
            else{
                //first number is bigger than second
                //second will be replaced
                if(temp[digit_sum][0]>temp[digit_sum][1])
                temp[digit_sum][1]=nums[i];
                //second is bigger than first
                //first will be replaced
                else
                temp[digit_sum][0]=nums[i];
            }
        }
    }
        int ans=-1;
        for(int i=0;i<82;i++){
            if(temp[i][0]==-1||temp[i][1]==-1){
                continue;
            }
            ans=max(ans,temp[i][0]+temp[i][1]);
        }
        return ans;
    }
};