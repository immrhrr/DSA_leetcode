class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, int src, int& ans,
             vector<bool>&vis) {
        vis[src] = true;
        for (int i = 0; i < adj[src].size(); i++) {
            int ngbr = adj[src][i].first;
            int dist = adj[src][i].second;
             ans = min(ans, dist);
            if (vis[ngbr])
                continue;
            dfs(adj, ngbr, ans, vis);
        }
        return;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        int ans = INT_MAX;
        vector<bool> vis(n + 1, false);
        dfs(adj, 1, ans, vis);
        return ans;
    }
};