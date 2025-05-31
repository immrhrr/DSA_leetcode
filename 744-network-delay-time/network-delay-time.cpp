class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back(make_pair(v, wt)); // using push_back instead of emplace_back
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0, k)); // using push instead of emplace

        while (!pq.empty()) {
            pair<int, int> it = pq.top();
            pq.pop();

            int d = it.first;
            int node = it.second;

            // ✅ skip stale entries
            if (d > dist[node]) continue;

            for (int i = 0; i < adj[node].size(); i++) {
                int next = adj[node][i].first;
                int weight = adj[node][i].second;

                if (d + weight < dist[next]) {
                    dist[next] = d + weight;
                    pq.push(make_pair(dist[next], next)); // using push
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};
