class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans;
        int maxi=-1;
        for (int i = 1; i < n - 1; i++) {
            vector<int> temp;
            maxi=0;
            for (int j = 1; j < n - 1; j++) {
                maxi = max( {
                    grid[i][j],grid[i][j + 1],grid[i][j - 1], 
                    grid[i + 1][j],grid[i + 1][j + 1],grid[i + 1][j - 1],
                    grid[i-1][j],grid[i-1][j+1],grid[i-1][j-1]
                });
                temp.push_back(maxi);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};