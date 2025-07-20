class Solution {
public:
    bool isPossible(int minEdgeCost, int n, vector<vector<pair<int, int>>>& adj, vector<bool>& online, long long k) {
        using T = pair<long long, int>; // (cost_so_far, node)
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<long long> dist(n, LLONG_MAX);

        if (!online[0]) return false;

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty()) {
            auto [cost, u] = pq.top(); pq.pop();

            if (u == n - 1) {
                return cost <= k;
            }

            for (auto [v, c] : adj[u]) {
                if (!online[v] || c < minEdgeCost) continue;

                long long new_cost = cost + c;
                if (new_cost < dist[v]) {
                    dist[v] = new_cost;
                    pq.push({new_cost, v});
                }
            }
        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int maxEdge = 0;

        for (auto& e : edges) {
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            maxEdge = max(maxEdge, c);
        }

        int low = 0, high = maxEdge, ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (isPossible(mid, n, adj, online, k)) {
                ans = mid;
                low = mid + 1; // try for a better (higher) minimum edge
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
