class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //kth  missing positive integer
        //sorted array given hai
        int low=0;
        int n=arr.size();
        int high=n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int missing=arr[mid]-(mid+1);
            if(missing>=k){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return high+k+1;

        
    }
};