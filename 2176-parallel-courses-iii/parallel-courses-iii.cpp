class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);
        for (auto it : relations) {
            int u = it[0];
            int v = it[1];
            adj[u - 1].push_back(v - 1);
            indegree[v - 1]++;
        }
        queue<int> q;
        vector<int> dp = time;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int i = 0; i < adj[node].size(); i++) {
                int ngbr = adj[node][i];
                dp[ngbr] = max(dp[ngbr], dp[node] + time[ngbr]);
                indegree[ngbr]--;
                if (indegree[ngbr] == 0) {
                    q.push(ngbr);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};