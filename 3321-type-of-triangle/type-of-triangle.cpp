class Solution {
public:
    string triangleType(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[1];
        int c=nums[2];
        if(a==b&&b==c){
            return "equilateral";
        }
        if(a+b>c){
            if(a==b||b==c)return "isosceles";
            if(a!=b&&b!=c)return "scalene";
        }
        
        return "none";
        
    }
};