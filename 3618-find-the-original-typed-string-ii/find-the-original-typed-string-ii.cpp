class Solution {
public:
    int mod = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.size();
        if (k > n) return 0;

        vector<int> pref;
        int cnt = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) cnt++;
            else {
                pref.push_back(cnt);
                cnt = 1;
            }
        }
        pref.push_back(cnt);
        int m = pref.size();

        long long total = 1;
        for (int i = 0; i < m; i++) {
            total = (total * pref[i]) % mod;
        }

        if (m >= k) return total;

        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < k; i++) {
            dp[m][i] = 1;
        }

        for (int ind = m - 1; ind >= 0; ind--) {
            vector<long long> arr(k + 1, 0);
            for (int i = 0; i < k; i++) {
                arr[i + 1] = (arr[i] + dp[ind + 1][i]) % mod;
            }

            for (int count = k - 1; count >= 0; count--) {
                int left = count + 1;
                int right = count + pref[ind];
                if (right >= k) right = k - 1;

                if (left <= right) {
                    dp[ind][count] = (arr[right + 1] - arr[left] + mod) % mod;
                }
            }
        }

        int invalid = dp[0][0];
        return (total - invalid + mod) % mod;
    }
};
