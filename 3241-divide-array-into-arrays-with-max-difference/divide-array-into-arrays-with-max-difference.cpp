class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int m=n/3;
        vector<vector<int>>ans(m,vector<int>(3,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<3;j++){
                int ind=3*i+j;
                if(j==0){
                    ans[i][0]=nums[ind];
                    //ans[i].push_back(nums[ind]);
                }
                else if(j==1){
                    if(nums[ind]-nums[ind-1]>k){
                        return {};
                    }
                    ans[i][1]=nums[ind];
                    //ans[i].push_nack(nums[ind]);
                }
                else{
                    if(nums[ind]-nums[ind-1]>k||nums[ind]-nums[ind-2]>k){
                        return {};
                    }
                    ans[i][2]=nums[ind];
                    //ans[i].push_nack(nums[ind]);
                }
            }
        }
        return ans;
        
    }
};