class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0&&(n & (n - 1)) == 0;
    }
    // technologia: n & n-1 is zero then n is a power of 2
};
