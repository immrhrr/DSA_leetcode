class Solution {
public:
    vector<vector<int>> dp;

    int solve(string &s, string &t, int i, int j) {
        // i = length of s considered, j = length of t considered
        if (j == 0) return 1;  // matched all of t
        if (i == 0) return 0;  // ran out of s before matching t

        if (dp[i][j] != -1) return dp[i][j];

        int take = 0, notake = 0;
        if (s[i - 1] == t[j - 1]) { // match last chars
            take = solve(s, t, i - 1, j - 1);
        }
        notake = solve(s, t, i - 1, j);

        return dp[i][j] = take + notake;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(s, t, n, m); // pass lengths
    }
};
