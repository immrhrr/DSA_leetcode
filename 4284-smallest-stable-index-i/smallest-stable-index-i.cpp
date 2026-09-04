class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        //instability= left max-right min
        //if instability is less than or equal to k -> stable
        //smallest stable index
        vector<int>right(n);
        right[0]=nums[0];
        vector<int>left(n);
        left[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            right[i]=max(nums[i],right[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            left[i]=min(left[i+1],nums[i]);
        }
        
        for(int i=0;i<n;i++){
            if(right[i]-left[i]<=k){
                return i;
            }
        }
        return -1;
    }
};