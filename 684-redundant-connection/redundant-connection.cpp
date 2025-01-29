class Solution {
public:
   bool dfs(unordered_map<int,vector<int>>&adj,int curr,int &destination,vector<bool>&vis){
    vis[curr]=true;
    
    int n=adj[curr].size();
    for(int i=0;i<n;i++){
        int ngbr=adj[curr][i];
         if(ngbr==destination){
            return true;
    }
        if(vis[ngbr]==false){
            vis[ngbr]=true;
           
            if(dfs(adj,ngbr,destination,vis)){
                return true;

            }
        }
    }
    return false;
   }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            vector<bool>vis(n,false);
            if(adj.find(u)!=adj.end()&&adj.find(v)!=adj.end()&&dfs(adj,u,v,vis)){
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};