class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        vector<vector<int>> pref(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[j][i] = matrix[j][i] + (i > 0 ? pref[j][i - 1] : 0);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i; j < m; j++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int curr=0;
                for (int k = 0; k < n; k++) {
                    curr+=pref[k][j]-(i>0?pref[k][i-1]:0);
                    int need=curr-target;
                    if(mp.find(need)!=mp.end()){
                        cnt+=mp[need];
                    }
                    mp[curr]++;
                }
            }
        }
        return cnt;
    }
};