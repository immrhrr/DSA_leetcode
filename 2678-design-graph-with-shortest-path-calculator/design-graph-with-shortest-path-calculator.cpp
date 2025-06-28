class Graph {
public:
    vector<vector<pair<int,int>>>adj;
    int N;
    //min heap
    //pair<int,int>
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    Graph(int n, vector<vector<int>>& edges) {
        N=n;
        adj.resize(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int cost=it[2];
            adj[u].push_back({v,cost});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u=edge[0];
        int v=edge[1];
        int cost=edge[2];
        adj[u].push_back({v,cost});
        
    }
    
    int shortestPath(int node1, int node2) {
        vector<int>dist(N,1e9);
        dist[node1]=0;
        pq.push({0,node1});
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            //cost says the cost from node 1 to the node
            int cost=it.first;
            int node=it.second;
            for(int i=0;i<adj[node].size();i++){
                int ngbr=adj[node][i].first;
                int paisa=adj[node][i].second;
                if(dist[ngbr]>cost+paisa){
                    dist[ngbr]=cost+paisa;
                    pq.push({dist[ngbr],ngbr});
                }
            }
        }
        return dist[node2]==1e9?-1:dist[node2];
        
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */