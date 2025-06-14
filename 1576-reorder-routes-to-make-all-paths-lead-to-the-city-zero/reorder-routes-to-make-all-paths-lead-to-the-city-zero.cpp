class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        // 1-> asli edge
        // 0->nakli edges
        vector<bool> vis(n, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int cnt = 0;
        // if we use nakli edge to go away from 0 then it is okay
        // but we we use the asli edge to go away from 0 then cnt++;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int i = 0; i < adj[curr].size(); i++) {
                int ngbr = adj[curr][i].first;
                int check=adj[curr][i].second;
                if (!vis[ngbr]) {
                    vis[ngbr] = true;
                    if(check==1){
                         cnt++;
                    }
                    q.push(ngbr);
                }
            }
        }
        return cnt;
    }
};