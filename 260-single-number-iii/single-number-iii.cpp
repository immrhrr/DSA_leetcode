class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long xorr=0;
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        long long set_bit=xorr&-xorr;
        int g0=0;
        int g1=0;
        for(int i=0;i<n;i++){
            if(set_bit&nums[i]){
                g1=g1^nums[i];
            }
            else{
                g0=g0^nums[i];
            }
        }
        return {g0,g1};
        
        
    }
};