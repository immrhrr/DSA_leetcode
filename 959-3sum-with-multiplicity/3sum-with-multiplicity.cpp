class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> count;

        // Count frequency of each number
        for (int x : arr) {
            count[x]++;
        }

        long long ans = 0;

        // Iterate over all pairs (a, b) in the map
        for (auto& [a, ca] : count) {
            for (auto& [b, cb] : count) {
                int c = target - a - b;
                if (!count.count(c)) continue;

                // Enforce ordering to avoid overcounting
                if (a > b || b > c) continue;

                long long cc = count[c];

                // Case 1: all values are the same (a == b == c)
                if (a == b && b == c) {
                    ans += ca * (ca - 1) * (ca - 2) / 6;
                }
                // Case 2: two values are the same (a == b != c)
                else if (a == b && b != c) {
                    ans += ca * (ca - 1) / 2 * cc;
                }
                // Case 3: two values are the same (a != b == c)
                else if (a != b && b == c) {
                    ans += cb * (cb - 1) / 2 * ca;
                }
                // Case 4: all values are different
                else if (a < b && b < c) {
                    ans += ca * cb * cc;
                }

                ans %= MOD;
            }
        }

        return (int)ans;
    }
};
