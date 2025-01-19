class Solution {
public:
    typedef pair<int,pair<int,int>>PP;
    vector<vector<int>>directions={{0,-1},{0,1},{-1,0},{1,0}};

    int trapRainWater(vector<vector<int>>& height) {
        int m=height.size();
        int n=height[0].size();
        priority_queue<PP,vector<PP>,greater<PP>>pq;
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        for(int row=0;row<m;row++){
            pq.push({height[row][0],{row,0}});
            pq.push({height[row][n-1],{row,n-1}});
            vis[row][0]=true;
            vis[row][n-1]=true;
        }
        for(int col=0;col<n;col++){
            pq.push({height[0][col],{0,col}});
            pq.push({height[m-1][col],{m-1,col}});
            vis[0][col]=true;
            vis[m-1][col]=true;
        }
        int water=0;
        while(!pq.empty()){
            PP p=pq.top();
            pq.pop();
            int h=p.first;
            int i=p.second.first;
            int j=p.second.second;
            for(vector<int>&dir:directions){
                int i_=i+dir[0];
                int j_=j+dir[1];
                if(i_>=0&&i_<m&&j_>=0&&j_<n&&!vis[i_][j_]){
                    water+=max(h-height[i_][j_],0);
                    pq.push({max(h,height[i_][j_]),{i_,j_}});
                    vis[i_][j_]=true;
                }
            }
        }
        return water;
    }
};