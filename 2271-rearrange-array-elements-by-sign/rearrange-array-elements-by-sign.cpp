class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=0;
        vector<int>ans;
        bool pos=true;
        while(i<n&&j<n){
            if(pos){
                while(i<n&&nums[i]<0){
                    i++;
                }
                ans.push_back(nums[i]);
                i++;
                pos=false;
            }
            else{
                while(j<n&&nums[j]>0){
                    j++;
                }
                ans.push_back(nums[j]);
                j++;
                pos=true;
            }

        }
        while(j<n&&nums[j]>0){
            j++;
        }
        if(j<n)
        ans.push_back(nums[j]);
        return ans;
        
    }
};