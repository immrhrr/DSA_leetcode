class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        //undirected 
        //n cities
        vector<int>indegree(n,0);
        vector<vector<int>>adj(n,vector<int>(n,0));
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            adj[u][v]++;
            adj[v][u]++;
            indegree[u]++;
            indegree[v]++;
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int curr=indegree[i]+indegree[j]-adj[i][j];
                ans=max(ans,curr);

            }
        }
        return ans;
        
    }
};