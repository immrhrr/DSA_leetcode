class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succ, int src, int dst) {
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double pro=succ[i];
            adj[u].push_back({v,pro});
            adj[v].push_back({u,pro});
        }
        priority_queue<pair<double,int>>pq;
        vector<double>dist(n,0);
        dist[src]=1;
        pq.push({1,src});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            double p=it.first;
            int node=it.second;
            for(int i=0;i<adj[node].size();i++){
                int ngbr=adj[node][i].first;
                double pro=adj[node][i].second;
                if(dist[ngbr]<pro*p){
                    dist[ngbr]=pro*p;
                    pq.push({dist[ngbr],ngbr});
                }
            }

        }
        return dist[dst];
    }
};