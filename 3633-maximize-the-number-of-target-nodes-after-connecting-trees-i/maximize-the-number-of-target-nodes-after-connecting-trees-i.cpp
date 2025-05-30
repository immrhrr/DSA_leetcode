class Solution {
public:
    void dfs(vector<vector<int>>& adj, int src, int& cnt, int k, vector<bool>& vis) {
        if (k <= 0) return;
        for (int neighbor : adj[src]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                cnt++;
                dfs(adj, neighbor, cnt, k - 1, vis);
            }
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // First, determine the actual number of nodes
        int maxNode1 = 0, maxNode2 = 0;
        for (auto& e : edges1) {
            maxNode1 = max({maxNode1, e[0], e[1]});
        }
        for (auto& e : edges2) {
            maxNode2 = max({maxNode2, e[0], e[1]});
        }

        // Build adjacency lists
        vector<vector<int>> adj1(maxNode1 + 1);
        vector<vector<int>> adj2(maxNode2 + 1);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> result1(maxNode1 + 1, 1);  // include self
        vector<int> result2(maxNode2 + 1, 1);
        if(k==0)return result1;

        for (int src = 0; src <= maxNode1; src++) {
            vector<bool> vis(maxNode1 + 1, false);
            vis[src] = true;
            int cnt = 1;
            dfs(adj1, src, cnt, k, vis);
            result1[src] = cnt;
        }
        

        for (int src = 0; src <= maxNode2; src++) {
            vector<bool> vis(maxNode2 + 1, false);
            vis[src] = true;
            int cnt = 1;
            dfs(adj2, src, cnt, k - 1, vis);
            result2[src] = cnt;
        }

        int maxi = *max_element(result2.begin(), result2.end());

        for (int i = 0; i < result1.size(); i++) {
            result1[i] += maxi;
        }

        return result1;
    }
};
