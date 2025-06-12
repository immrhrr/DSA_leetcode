class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src,
                          int dest, int k) {
        if (src == dest)
            return 0;
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int price = it[2];
            adj[u].push_back({v, price});
        }
        queue<pair<int, int>> q;
        q.push({0, src});
        int steps = -1;
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!q.empty()) {
            if (steps >= k)
                break;
            int m = q.size();
            while (m--) {
                auto it = q.front();
                int price = it.first;
                int city = it.second;
                q.pop();
                for (int i = 0; i < adj[city].size(); i++) {
                    int ngbr = adj[city][i].first;
                    int cost = adj[city][i].second;
                    if (dist[ngbr] > price + cost) {
                        dist[ngbr] = price + cost;
                        q.push({dist[ngbr], ngbr});
                    }
                }
            }
            steps++;
        }
        return dist[dest] == INT_MAX ? -1 : dist[dest];
    }
};