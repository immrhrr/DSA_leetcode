class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        //minimum cost
        long long ans=0;
        if(n<=k&&m<=k)return ans;
        else{
            int maxi=max(n,m);
            ans=(long long) (maxi-k)*(long long) (k);
            return ans;
        }
        return ans;

        
    }
};