class Solution {
public:
    void bfs(vector<vector<int>>adj,int src,vector<bool>&vis,vector<vector<int>>&arr){
        queue<int>q;
        q.push(src);
        vis[src]=true;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                if(vis[adj[curr][i]]==false){
                    q.push(adj[curr][i]);
                    vis[adj[curr][i]]=true;
                }
            }
        }
        int n=adj.size();
        for(int i=0;i<n;i++){
            if(vis[i]){
                arr[src].push_back(i);
            }
        }
        return;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>>adj(n);
        for(auto it:richer){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
        }
        vector<vector<int>>arr(n);
        for(int i=0;i<n;i++){
            vector<bool>vis(n,false);
            bfs(adj,i,vis,arr);
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int m=arr[i].size();
            int mini=INT_MAX;
            int ind=-1;
            for(int j=0;j<m;j++){
                if(quiet[arr[i][j]]<mini){
                    mini=quiet[arr[i][j]];
                    ind=arr[i][j];
                }
                
            }
            ans[i]=ind;
        }
        return ans;
        
    }
};