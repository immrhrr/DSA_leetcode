class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<vector<int>>&grid,int r,int c){
        int nrow=grid.size();
        int ncol=grid[0].size();
        if(r>=nrow||c>=ncol){
            return 1e5;
        }
        if(r==nrow-1&&c==ncol-1){
            return grid[r][c];
        }
        if(dp[r][c]!=1e9)return dp[r][c];
        int temp=INT_MAX;
        int right=1e5;
        int down=1e5;
        right=grid[r][c]+solve(grid,r,c+1);
        down=grid[r][c]+solve(grid,r+1,c);
        temp=min({temp,right,down});
        return dp[r][c]= temp;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int nrow=grid.size();
        int ncol=grid[0].size();
        dp.resize(nrow, vector<int>(ncol, 1e9));
        return solve(grid,0,0);
    }
};