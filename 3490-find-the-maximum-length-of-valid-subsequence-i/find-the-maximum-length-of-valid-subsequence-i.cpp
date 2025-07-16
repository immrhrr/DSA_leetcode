class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //odd odd
        //even even
        //odd even
        //even odd
        int n=nums.size();
        int odd=0;
        int even=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
        }
        int odd_even=0;
        int even_odd=0;
        bool check_odd=true;
        for(int i=0;i<n;i++){
            if(check_odd&&nums[i]%2==1){
                check_odd=false;
                odd_even++;
            }
            if(!check_odd&&nums[i]%2==0){
                check_odd=true;
                odd_even++;
            }
        }

         bool check_even=true;
        for(int i=0;i<n;i++){
            if(check_even&&nums[i]%2==0){
                check_even=false;
                even_odd++;
            }
            if(!check_even&&nums[i]%2==1){
                check_even=true;
                even_odd++;
            }
        }
        return max({odd,even,odd_even,even_odd});
        
    }
};