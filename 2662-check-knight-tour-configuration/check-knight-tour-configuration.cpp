class Solution {
public:
    vector<int>h={1,2,2,1,-1,-2,-2,-1};
    vector<int>v={2,1,-1,-2,-2,-1,1,2};
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]!=0)return false;
        unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]={i,j};
            }
        }
        for(int i=1;i<n*n;i++){
            int prev_r=mp[i-1].first;
            int prev_c=mp[i-1].second;
            int curr_r=mp[i].first;
            int curr_c=mp[i].second;
            bool flag=false;
            for(int j=0;j<8;j++){
                int nrow=prev_r+h[j];
                int ncol=prev_c+v[j];
                if(nrow==curr_r&&ncol==curr_c){
                    flag=true;
                    break;
                }
            }
            if(!flag)return false;
        }
        return true;
    }
};