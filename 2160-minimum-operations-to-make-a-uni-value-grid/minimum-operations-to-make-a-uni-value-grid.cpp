class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        int rem=grid[0][0]%x;
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]%x!=rem){
                    return -1;
                }
                temp.push_back(grid[i][j]);
            }
        }
        int mid_ind=(n*m)/2;
        if((n*m)%2==0)mid_ind--;
        int ans=0;
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++){
            ans+=abs(temp[i]-temp[mid_ind])/x;
        }
        return ans;
        
    }
};