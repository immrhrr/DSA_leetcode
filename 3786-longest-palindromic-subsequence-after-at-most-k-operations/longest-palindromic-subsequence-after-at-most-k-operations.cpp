class Solution {
public:
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 0)));

        // Base case: Single character palindromes
        for (int i = 0; i < n; i++) {
            for (int rem = 0; rem <= k; rem++) {
                dp[i][i][rem] = 1;
            }
        }

        // Fill DP table for substrings of length 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                for (int rem = 0; rem <= k; rem++) {
                    // Skip characters (delete)
                    int op1 = dp[i + 1][j][rem];
                    int op2 = dp[i][j - 1][rem];

                    // Try matching s[i] and s[j]
                    int op3 = 0;
                    if (s[i] == s[j]) {
                        op3 = 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1][rem] : 0);
                    } else {
                        int d1 = abs(s[i] - s[j]);
                        int d2 = 26 - d1;
                        int steps = min(d1, d2);
                        if (rem >= steps) {
                            op3 = 2 + (i + 1 <= j - 1 ? dp[i + 1][j - 1][rem - steps] : 0);
                        }
                    }

                    dp[i][j][rem] = max({op1, op2, op3});
                }
            }
        }

        return dp[0][n - 1][k];
    }
};
