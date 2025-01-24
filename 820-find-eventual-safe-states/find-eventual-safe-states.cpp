class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int u,vector<int>&vis,vector<int>&inRecursion){
        vis[u]=1;
        inRecursion[u]=1;
        int n=graph[u].size();
        for(int i=0;i<n;i++){
            int v=graph[u][i];
            if(vis[v]==-1&& dfs(graph,v,vis,inRecursion)){
               return true;
            }
            else {
                if(inRecursion[v]==1){
                    return true;
                }
               
            }
        }
        inRecursion[u]=-1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int n=graph.size();
        vector<int>vis(n,-1);
        vector<int>inRecursion(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                dfs(graph,i,vis,inRecursion);
            }
        }
        for(int i=0;i<n;i++){
            if(inRecursion[i]==-1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};