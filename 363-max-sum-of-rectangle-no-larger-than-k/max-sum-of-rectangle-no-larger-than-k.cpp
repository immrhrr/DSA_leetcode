class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxi = INT_MIN;
        for (int i = 0; i < m; i++) {
            vector<int> arr(n, 0);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    arr[k] += matrix[k][j];
                }
                set<int> st;
                st.insert(0);
                int curr = 0;
                for (auto it : arr) {
                    curr += it;
                    int need = curr - k;
                    auto itt = st.lower_bound(curr - k);
                    if (itt != st.end()) {
                        maxi = max(maxi, curr - *itt);
                    }
                    st.insert(curr);
                }
            }
        }
        return maxi;
    }
};