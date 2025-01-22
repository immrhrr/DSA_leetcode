class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& water) {
        int n=water.size();
        int m=water[0].size();
        vector<vector<int>>ans(n,vector<int>(m,-1));
        //store the water cell in the queue
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(water[i][j]==1){
                    q.push({0,{i,j}});
                    ans[i][j]=0;
                }
            }
        }
        vector<vector<int>>direction={{1,0},{0,-1},{-1,0},{0,1}};
        while(!q.empty()){
            int val=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+direction[i][0];
                int ncol=c+direction[i][1];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&ans[nrow][ncol]==-1){
                    ans[nrow][ncol]=val+1;
                    q.push({val+1,{nrow,ncol}});
                }
            }
        }
        return ans;

    }
};