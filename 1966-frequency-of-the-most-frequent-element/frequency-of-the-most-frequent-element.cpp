class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long>pref(n,0);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        int ans=1;
        for(int j=n-1;j>0;j--){
            //we have to find i value
            int low=0;
            int high=j-1;
            int temp=1;
            while(low<=high){
                int mid=low+(high-low)/2;
                long long  size=j-mid+1;
                long long need=size*nums[j];
                long long curr=pref[j]+k;
                if(mid-1>=0){
                    curr=curr-pref[mid-1];
                }
                if(curr>=need){
                    high=mid-1;
                    temp=size;
                }
                else{
                    low=mid+1;
                }
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};
//3 6 9
// k=2
//3 9 18
