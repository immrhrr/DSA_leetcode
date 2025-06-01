class Solution {
public:
    int solve(unordered_set<int> st) {
        vector<int> num;
        for (auto it : st) {
            num.push_back(it);
        }
        // int ans=INT_MAX;
        // for(int i=0;i<num.size();i++){
        //     for(int j=i+1;j<num.size();j++){
        //         ans=min(ans,abs(num[i]-num[j]));
        //     }
        // }
        // return ans;
        sort(num.begin(), num.end());
        int ans = INT_MAX;
        for (int i = 1; i < num.size(); ++i)
            ans = min(ans, num[i] - num[i - 1]);
        return ans;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1, 0));
        for (int i = 0; i < m - k + 1; i++) {
            for (int j = 0; j < n - k + 1; j++) {
                unordered_set<int> st;
                for (int l = i; l < i + k; l++) {
                    for (int m = j; m < j + k; m++) {
                        st.insert(grid[l][m]);
                    }
                }
                if (st.size() == 1) {
                    continue;
                }
                ans[i][j] = solve(st);
            }
        }
        return ans;
    }
};