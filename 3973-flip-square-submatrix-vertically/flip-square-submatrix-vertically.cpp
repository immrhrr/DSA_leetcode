class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n=grid.size();
        int m=grid[0].size();
        //vector<vector<int>>ans(n,vector<int>(m,0));
        //ans=grid;
        for(int i=y;i<y+k;i++){
            vector<int>arr(k);
            for(int j=x;j<x+k;j++){
                arr[j-x]=grid[j][i];
            }
            //reverse(arr.begin(),arr.end());
            int ind=0;
            for(int j=x+k-1;j>=x;j--){
                grid[j][i]=arr[ind++];
            }
        }
        return grid;
        
    }
};