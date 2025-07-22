class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        vector<long long> cost(n, LLONG_MAX);
        vector<int> ways(n, 0);
        ways[0] = 1;
        cost[0] = 0;
        //priority_queue<pair<int, long long>, vector<pair<int, long long>>,greater<pair<int, long long>>>pq;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        pq.push({0, 0});
        // cost,node;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            long long time = it.first;
            int node = it.second;
            if(cost[node]<time){
                continue;
            }
            for (int i = 0; i < adj[node].size(); i++) {
                int ngbr = adj[node][i].first;
                int wt = adj[node][i].second;
                if (cost[ngbr] > time + wt) {
                    cost[ngbr] = time + wt;
                    ways[ngbr] = ways[node];
                    pq.push({cost[ngbr],ngbr});
                } else if (cost[ngbr] == time + wt) {
                    ways[ngbr] = (ways[ngbr]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};