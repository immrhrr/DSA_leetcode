class Solution {
public:
   void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&dis,vector<bool>&vis,vector<int>&low,vector<vector<int>>&ans,int&temp){
    dis[node]=temp;
    low[node]=temp;
    vis[node]=true;
    for(int i=0;i<adj[node].size();i++){
        int ngbr=adj[node][i];
        if(parent==ngbr){
            continue;
        }
        else if(vis[ngbr]){
            low[node]=min(low[node],low[ngbr]);
        }
        else{
            temp++;
            dfs(ngbr,node,adj,dis,vis,low,ans,temp);
            low[node]=min(low[node],low[ngbr]);
            //bridge hai wala condition
            if(dis[node]<low[ngbr]){
                vector<int>bridge;
                bridge.push_back(node);
                bridge.push_back(ngbr);
                ans.push_back(bridge);
            }
        }
    }
    return;
   }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>>adj(n);
        for(int i=0;i<con.size();i++){
            int u=con[i][0];
            int v=con[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>dis(n);
        vector<int>low(n);
        vector<bool>vis(n,0);
        vector<vector<int>>ans;
        int temp=0;
        int start=0;
        int parent=-1;
        dfs(start,parent,adj,dis,vis,low,ans,temp);
        return ans;

    }
};