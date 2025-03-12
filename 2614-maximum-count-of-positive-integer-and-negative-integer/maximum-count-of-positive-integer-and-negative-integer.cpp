class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        //find the last negative number index
        //find the first positive number index
        //pos=n_index+1
        //neg=n-p_index
        //return max(pos,neg)
        int n_index=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int mid_val=nums[mid];
            if(mid_val>=0){
                //go left
                high=mid-1;
            }
            else{
                //go right
                n_index=mid;
                low=mid+1;
            }
        }
        low=0;
        high=n-1;
        int p_index=-1;
         while(low<=high){
            int mid=low+(high-low)/2;
            int mid_val=nums[mid];
            if(mid_val>0){
                //go left
                p_index=mid;
                high=mid-1;
            }
            else{
                //go right
               
                low=mid+1;
            }
        }

        int neg=n_index+1;
        int pos=n-p_index;
        if(p_index==-1){
            return neg;
        }
        if(n_index==-1){
            return pos;
        }
        return max(pos,neg);
        
    }
};