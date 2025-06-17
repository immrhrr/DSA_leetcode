class Solution {
public:
    int mod = 1e9 + 7;

    // Iterative version of binary exponentiation
    int findPower(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 == 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b /= 2;
        }
        return res;
    }

    int nCr(int a, int b, vector<long long>& factorial, vector<long long>& fermatFact) {
        return (factorial[a] * fermatFact[a - b] % mod * fermatFact[b] % mod) % mod;
    }

    int countGoodArrays(int n, int m, int k) {
        vector<long long> factorial(n + 1, 1);
        for (int i = 2; i <= n; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
        }

        vector<long long> fermatFact(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            fermatFact[i] = findPower(factorial[i], mod - 2);
        }

        long long ans = nCr(n - 1, k, factorial, fermatFact);
        ans = (ans * m) % mod;
        ans = (ans * findPower(m - 1, n - k - 1)) % mod;

        return ans;
    }
};
