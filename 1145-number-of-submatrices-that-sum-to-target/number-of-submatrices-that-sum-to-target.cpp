class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        //cumulative sum ka matrix banao column wise
        vector<vector<int>> pref(n, vector<int>(m, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pref[j][i] = matrix[j][i] + (i > 0 ? pref[j][i - 1] : 0);
            }
        }
        for (int start_col = 0; start_col < m; start_col++) {
            for (int end_col = start_col; end_col < m; end_col++) {
                unordered_map<int, int> mp;
                mp[0] = 1;
                int curr=0;
                for (int row = 0; row < n; row++) {
                    curr+=pref[row][end_col]-(start_col>0?pref[row][start_col-1]:0);
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