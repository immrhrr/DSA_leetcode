class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1, 0});
        res.push_back({n, n - 1});
        sort(res.begin(), res.end());
        int m = res.size();
        
        for(int i = 1; i < m; i++){
            res[i][1] = min(res[i][1], res[i-1][1] + (res[i][0] - res[i-1][0]));
        }
        
        for(int i = m - 2; i >= 0; i--){
            res[i][1] = min(res[i][1], res[i+1][1] + (res[i+1][0] - res[i][0]));
        }
        
        int ans = 0;
        
        for(int i = 0; i < m - 1; i++){
            int temp = ((res[i+1][0] - res[i][0]) + (res[i+1][1] + res[i][1])) / 2;
            ans = max(ans, temp);
        }
        
        return ans;
    }
};