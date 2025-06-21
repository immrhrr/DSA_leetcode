class Solution {
public:
    int find(vector<int>& nums, int limit) {
    int n = nums.size();
    int low = 0, high = n - 1;
    int index = n; // Default to n in case all nums < limit

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= limit) {
            index = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return n - index; // Count of elements >= limit
}

    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=1;
        int high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int cnt=find(nums,mid);
            if(cnt==mid){
                return mid;
            }
            else if(cnt>mid){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};