class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<int>& vis, int src) {
        vis[src] = 1;
        int size = 1;  // Count the current node
        for (int ngbr : adj[src]) {
            if (vis[ngbr] == -1) {
                size += dfs(adj, vis, ngbr);
            }
        }
        return size;
    }

    bool check(vector<vector<int>>& adj, int need, int src, vector<bool>& vis) {
        vis[src] = true;
        for (int ngbr : adj[src]) {
            if (adj[ngbr].size() != need) return false;
            if (!vis[ngbr]) {
                if (!check(adj, need, ngbr, vis)) return false;
            }
        }
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int a = edge[0], b = edge[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n, -1);
        vector<int> comp(n, 0);
        int ans = 0;

        // Find connected components
        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                comp[i] = dfs(adj, vis, i);
            }
        }

        vector<bool> vis2(n, false);
        for (int i = 0; i < n; i++) {  // Fix: Iterate over `n` not `comp.size()`
            if (comp[i] > 0) {  // Ignore uninitialized values
                int need = comp[i] - 1;  // Complete graph of `n` nodes has `n-1` edges per node
                if (check(adj, need, i, vis2)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
