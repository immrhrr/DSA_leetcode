class Solution {
public:
    void dfs(vector<vector<int>>&adj,int &size,int curr,vector<bool>&vis){
        vis[curr]=true;
        size++;
        for(int i=0;i<adj[curr].size();i++){
            int ngbr=adj[curr][i];
            if(!vis[ngbr]){
                dfs(adj,size,ngbr,vis);
            }
        }
        return;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,false);
        long long ans=0;
        int rem=n;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int size=0;
                dfs(adj,size,i,vis);
                rem=rem-size;
                ans=ans+(long long)size*rem;
            }
        }
        return ans;
        
    }
};