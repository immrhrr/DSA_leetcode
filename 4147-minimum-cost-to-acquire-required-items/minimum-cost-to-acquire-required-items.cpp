class Solution {
public:
    long long minimumCost(int c1, int c2, int c3, int n1, int n2) {
        long long common = min(n1, n2);
        long long maxi = max(n1, n2);
        long long ans = 0;
        ans += common * min(1LL * c1 + c2, 1LL * c3);
        if (n1 > n2) {
            ans += (n1 - common) * min(c1, c3);
        } 
        else {
            ans += (n2 - common) * min(c2, c3);
        }
        return ans;
    }
};