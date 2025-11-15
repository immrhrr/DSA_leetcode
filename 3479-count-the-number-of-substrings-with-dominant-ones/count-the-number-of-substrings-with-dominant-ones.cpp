#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = (int)s.size();
        long long ans = 0;

        // collect positions of zeros
        vector<int> zeros;
        for (int i = 0; i < n; ++i) if (s[i] == '0') zeros.push_back(i);

        // handle k = 0: substrings consisting only of '1's
        long long run = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') run++;
            else {
                ans += run * (run + 1) / 2;
                run = 0;
            }
        }
        ans += run * (run + 1) / 2;

        if (zeros.empty()) return ans; // no zeros, done

        int Z = (int)zeros.size();
        // max k we need to try: if k^2 <= n then k <= sqrt(n)
        int Kmax = (int)floor(sqrt(n)) + 1;
        for (int k = 1; k <= Kmax; ++k) {
            if (k > Z) break; // cannot have more zeros than exist

            long long requiredLen = 1LL * k * k + k; // L >= k^2 + k

            // slide over all windows of exactly k zeros: zeros[t] ... zeros[t+k-1]
            for (int t = 0; t + k - 1 < Z; ++t) {
                int a = t;
                int b = t + k - 1;
                // minimal length covering these k zeros
                int minLen0 = zeros[b] - zeros[a] + 1;

                // number of ones available to extend on left and right
                int prevZeroPos = (a == 0 ? -1 : zeros[a - 1]);
                int nextZeroPos = (b + 1 == Z ? n : zeros[b + 1]);

                int extraLeft = zeros[a] - prevZeroPos - 1;   // how many ones can be added left
                int extraRight = nextZeroPos - zeros[b] - 1;  // how many ones can be added right

                long long needExtra = requiredLen - minLen0; // extra ones required beyond minLen0
                if (needExtra <= 0) {
                    // every combination of left/right extensions works
                    ans += 1LL * (extraLeft + 1) * (extraRight + 1);
                    continue;
                }
                if (needExtra > (long long)extraLeft + extraRight) {
                    // even using all available ones can't reach required length
                    continue;
                }

                // total pairs of (addLeft, addRight)
                long long totalPairs = 1LL * (extraLeft + 1) * (extraRight + 1);

                // count pairs with sum < needExtra and subtract them
                // for addLeft in [0..extraLeft], allowed addRight < needExtra - addLeft
                long long badPairs = 0;
                for (int addLeft = 0; addLeft <= extraLeft; ++addLeft) {
                    long long maxRightAllowed = needExtra - 1 - addLeft;
                    if (maxRightAllowed < 0) {
                        // no right values produce sum < needExtra for this addLeft
                        continue;
                    }
                    // right choices are 0..min(extraRight, maxRightAllowed)
                    long long cntRight = min<long long>(extraRight, maxRightAllowed) + 1;
                    badPairs += cntRight;
                }

                ans += (totalPairs - badPairs);
            }
        }

        return ans;
    }
};
