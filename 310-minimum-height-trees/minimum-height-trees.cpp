class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return{0};
        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);
        for (int i = 0; i < n - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            degree[u] += 1;
            degree[v] += 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        int cnt = n;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int m = q.size();
            if (cnt <= 2) {
                break;
            }
            while (m--) {
                int curr = q.front();
                q.pop();
                cnt--;
                for (int i = 0; i < adj[curr].size(); i++) {
                    int ngbr = adj[curr][i];
                    degree[ngbr]--;
                    if (degree[ngbr] == 1) {
                        q.push(ngbr);
                    }
                }
            }
        }
        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};