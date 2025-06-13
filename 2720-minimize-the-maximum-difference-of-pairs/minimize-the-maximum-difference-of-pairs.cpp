class Solution {
public:
    bool is_possible(vector<int>&nums,int &limit,int &p){
        int n=nums.size();
        int cnt=0;
        int last=-1;
        for(int i=1;i<n;i++){
            if(last==i-1){
                continue;
            }
            else{
                if(nums[i]-nums[i-1]<=limit){
                    cnt++;
                    last=i;
                }
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        //Find p pairs of indices of nums such that
        // maximum difference amongst all the pairs is minimized
        sort(nums.begin(),nums.end());
        //pairing can be done with the consecutives only
        //to get minimum absolute difference
        int n=nums.size();
        int low=0;
        int high=nums[n-1]-nums[0];
        int ans=-1;
        int mid;
        while(low<=high){
            mid=low+(high-low)/2;
            bool check=is_possible(nums,mid,p);
            if(check){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};