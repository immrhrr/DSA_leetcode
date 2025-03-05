class Solution {
public:
    long long coloredCells(int n) {
        if(n==1){
            return 1;
        }
        int curr=1;
        long long ans=1;
        long long temp=1;
        while(curr<n){
            ans+=(4*temp);
            curr++;
            temp++;
        }
        return ans;
    }
};