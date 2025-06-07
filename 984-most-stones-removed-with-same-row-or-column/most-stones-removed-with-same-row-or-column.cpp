class Solution {
public:
    void dfs(vector<vector<int>>&stones,vector<bool>&vis,int ind){
        vis[ind]=true;
        int r=stones[ind][0];
        int c=stones[ind][1];
        for(int i=0;i<stones.size();i++){
            if(vis[i]==false&&(r==stones[i][0]||c==stones[i][1])){
                dfs(stones,vis,i);
            }
        }
        return;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<bool>vis(n,false);
        int group=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(stones,vis,i);
                group++;
            }
        }
        return n-group;
        
    }
};