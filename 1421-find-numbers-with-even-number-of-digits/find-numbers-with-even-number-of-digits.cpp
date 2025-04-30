class Solution {
public:
    int find_digits(int n){
        int d=0;
        while(n>0){
            d++;
            n=n/10;
        }
        return d;
    }
    int findNumbers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int digits=0;
        for(int i=0;i<n;i++){
            digits=find_digits(nums[i]);
            if(digits%2==0){
                ans++;
            }
        }
        return ans;
        
    }
};