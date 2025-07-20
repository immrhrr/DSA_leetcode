class Solution {
public:
    int mod = 1e9 + 7;

    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[points[i][1]]++;
        }

        vector<long long> temp;
        for (auto it : mp) {
            long long curr = it.second;
            if (curr > 1) {
                temp.push_back((curr * (curr - 1) / 2) % mod);
            }
        }

        long long tot_sum = accumulate(temp.begin(), temp.end(), 0LL) % mod;
        int m = temp.size();
        long long ans = 0;
        for (int i = 0; i < m; i++) {
            long long add = ((tot_sum - temp[i] + mod) % mod * temp[i]) % mod;
            ans = (ans + add) % mod;
        }

        return (ans * ((mod + 1) / 2)) % mod; // or multiply by 500000004
    }
};
