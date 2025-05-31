class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& it : times) {
            int u = it[0], v = it[1], wt = it[2];
            adj[u].emplace_back(v, wt);
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k);

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            // ✅ Key line: skip if this is an outdated entry
            if (d > dist[node]) continue;

            for (auto& [next, weight] : adj[node]) {
                if (d + weight < dist[next]) {
                    dist[next] = d + weight;
                    pq.emplace(dist[next], next);
                }
            }
        }

        int ans = *max_element(dist.begin() + 1, dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};
