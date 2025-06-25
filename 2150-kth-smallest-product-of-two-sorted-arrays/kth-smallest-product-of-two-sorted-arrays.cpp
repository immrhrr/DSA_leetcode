class Solution {
public:
    long long solve(vector<int>&nums1,vector<int>&nums2,long long limit){
        int n1=nums1.size();
        int n2=nums2.size();
        long long tot=0;
        for(int i=0;i<n1;i++){
            long long first=nums1[i];
            if(first>=0){
                int ans=-1;
                int low=0;
                int high=n2-1;
                while(low<=high){
                    int mid=low+(high-low)/2;
                    long long pro=first*nums2[mid];
                    if(pro>limit){
                        high=mid-1;
                    }
                    else{
                        ans=mid;
                        low=mid+1;
                    }
                }
                tot+=(ans+1);
            }
            else{
                int ans=n2;
                int low=0;
                int high=n2-1;
                int mid;
                while(low<=high){
                    mid=low+(high-low)/2;
                    long long pro=first*nums2[mid];
                    if(pro>limit){
                        low=mid+1;
                    }
                    else{
                        ans=mid;
                        high=mid-1;
                    }
                }
                tot+=(n2-ans);
            }
        }
        return tot;

    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long high=1e10;
        long long low=-high;
        long long mid;
        long long ans;
        long long temp=0;
        while(low<=high){
            mid=low+(high-low)/2;
            //mid se kitna chhota product nums1 aur nums2 se aa skta hai
           long long cnt=solve(nums1,nums2,mid);
            if(cnt>=k){
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