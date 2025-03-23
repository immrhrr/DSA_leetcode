class Solution {
public:
    typedef pair<long long,int> P;
    
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<vector<P>>adj(n);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<int>count(n,0);
        count[0]=1;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            long long d=pq.top().first;
            int u=pq.top().second;
            pq.pop();
            //d matlab ki kitna distance lagega source se u tak jaane mein
            for(auto it:adj[u]){
                int wt=it.second;
                //wt matlab ki u se v jaane mein distane
                int v=it.first;
                if(wt+d==dist[v]){
                    count[v]=(count[v]+count[u])%mod;
                }
                if(wt+d<dist[v]){
                    dist[v]=d+wt;
                    pq.push({dist[v],v});
                    count[v]=count[u];

                }
            }
        }
        return count[n-1];

        
    }
};