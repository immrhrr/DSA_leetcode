class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        int n=nums.size();
        //find the first occ of val
        while(i<n&&nums[i]!=val){
            i++;
        }
        //no occ of val
        if(i==n)return n;
        int j=n-1;
        //find the first index from back where its not equal to val
        while(j>=0&&nums[j]==val){
            j--;
        }
        //all are equal to val
        if(j==-1)return 0;
        while(i<j){
            swap(nums[i],nums[j]);
            i++;
            j--;
            while(nums[i]!=val){
                i++;
            }
            while(nums[j]==val){
                j--;
            }
        }
        return i;
        
    }
};