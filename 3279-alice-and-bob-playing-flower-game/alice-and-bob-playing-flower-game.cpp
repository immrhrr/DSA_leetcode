class Solution {
public:
    long long flowerGame(int n, int m) {
        //odd=(even+odd) or (odd+even)
        long long first_odd=0;
        long long first_even=0;
        long long sec_odd=0;
        long long sec_even=0;
        first_odd=(n+1)/2;
        sec_odd=(m+1)/2;
        first_even=n-first_odd;
        sec_even=m-sec_odd;
        long long ans=0;
        long long t1=0,t2=0;
        t1=first_even*sec_odd;
        t2=first_odd*sec_even;
        ans=t1+t2;
        return ans;
        
    }
};