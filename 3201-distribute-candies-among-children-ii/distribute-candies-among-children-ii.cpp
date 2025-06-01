class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        int mini=max(0,n-2*limit);
        int maxi=min(n,limit);
        for(int c1=mini;c1<=maxi;c1++){
            int rem=n-c1;
            int c2_min=max(0,n-c1-limit);
            int c2_max=min(n-c1,limit);
            ans+=(c2_max-c2_min+1);
        }
        return ans;
        
    }
};