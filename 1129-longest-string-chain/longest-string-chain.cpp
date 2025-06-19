class Solution {
public:
    static bool cmpByLength(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

    bool check(vector<string>& words, int ind, int prev, vector<vector<int>>& dp2) {
        if (dp2[ind][prev] != -1) return dp2[ind][prev];
        string &s1 = words[ind];
        string &s2 = words[prev];

        if (s1.size() - s2.size() != 1) return dp2[ind][prev] = false;

        int i = 0, j = 0, cnt = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) {
                i++; j++;
            } else {
                i++; cnt++;
            }
            if (cnt > 1) return dp2[ind][prev] = false;
        }
        // One extra character at the end is fine
        return dp2[ind][prev] = true;
    }

    int solve(vector<string>& words, int ind, int prev_ind, vector<vector<int>>& dp, vector<vector<int>>& dp2) {
        if (ind >= words.size()) return 0;
        if (dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        int take = 0;
        if (prev_ind == -1 || check(words, ind, prev_ind, dp2)) {
            take = 1 + solve(words, ind + 1, ind, dp, dp2);
        }

        int notake = solve(words, ind + 1, prev_ind, dp, dp2);
        return dp[ind][prev_ind + 1] = max(take, notake);
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmpByLength);
        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));
        return solve(words, 0, -1, dp, dp2);
    }
};
