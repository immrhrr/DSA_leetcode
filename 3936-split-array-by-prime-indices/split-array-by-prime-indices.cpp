class Solution {
public:
    void helper(vector<bool>& is_prime) {

        is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime

        for (int i = 2; i * i <= 1e5; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= 1e5; j += i) {
                    is_prime[j] = false; // mark multiples as not prime
                }
            }
        }
    }
    long long splitArray(vector<int>& nums) {
        long long tot = accumulate(nums.begin(), nums.end(), 0ll);
        long long prime = 0;
        int n = nums.size();
        vector<bool> is_prime(1e5 + 1, true);
        helper(is_prime);
        for (int i = 0; i < n; i++) {
            if (is_prime[i]) {
                prime += nums[i];
            }
        }
        return abs((tot - prime) - prime);
    }
};