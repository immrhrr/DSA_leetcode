class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        // 1-> asli edge
        // 0-> nakli edge
        int cnt = 0;
        queue<int> q;
        q.push(0);
        vector<bool> vis(n, false);
        vis[0] = true;
        // if we use alsi edge to go away from 0 then cnt++
        // if we use nakli edge to go away then its fine
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < adj[curr].size(); i++) {
                int ngbr = adj[curr][i].first;
                if (vis[ngbr] == false) {
                    if (adj[curr][i].second == 1) {
                        cnt++;
                    }
                    vis[ngbr] = true;
                    q.push(ngbr);                }
            }
        }
        return cnt;
    }
};