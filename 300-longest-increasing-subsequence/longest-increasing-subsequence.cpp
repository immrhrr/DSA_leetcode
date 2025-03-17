class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        temp.push_back(INT_MIN);
        for(int i=0;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                //find the smallest number that is bigger than nums[i];
                //ans replace it with this
                int low=0;
                int high=temp.size()-1;
                int index=0;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    if(temp[mid]>=nums[i]){
                        index=mid;
                        high=mid-1;
                    }
                    else{
                      low=mid+1;
                    }
                }
                temp[index]=nums[i];
            }
        }
        return temp.size()-1;
        
    }
};