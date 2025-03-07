class Solution {
public:
    static vector<bool> isprime;
    static void precompute() {
        int n = isprime.size();
        isprime[0] = isprime[1] = false;  // 0 and 1 are not prime
        for (int i = 2; i * i < n; i++) {
            if (isprime[i]) {
                for (int j = i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        vector<int> prime;
        for (int i = left; i <= right; i++) {
            if (isprime[i]) {
                prime.push_back(i);
            }
        }
        int a = -1, b = -1, diff = INT_MAX;
        for (int i = 1; i < prime.size(); i++) {
            if (prime[i] - prime[i - 1] < diff) {
                diff = prime[i] - prime[i - 1];
                a = prime[i - 1];
                b = prime[i];
            }
        }
        return {a, b};
    }
};

// Initialize the static prime sieve
vector<bool> Solution::isprime(1e6 + 1, true);
struct PrimeInit {
    PrimeInit() { Solution::precompute(); }
} prime_initializer;
