class Solution {
public:
     bool bfs(int src,vector<int>&vis,vector<vector<int>>&adj){
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                int dislike=adj[curr][i];
                if(vis[dislike]==vis[curr])return false;
                if(vis[dislike]==-1){
                    vis[dislike]=vis[curr]==0? 1:0;
                    q.push(dislike);
                }
            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
         int n=graph.size();
      vector<int>vis(n,-1);
      for(int i=0;i<n;i++){
        if(vis[i]==-1){
            vis[i]=0;
            if(bfs(i,vis,graph)==false){
                return false;
            }
        }
      }
      return true;
        
    }
};