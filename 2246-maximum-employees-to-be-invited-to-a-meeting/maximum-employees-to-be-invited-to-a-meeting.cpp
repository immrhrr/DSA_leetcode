class Solution {
public:
    int bfs(unordered_map<int, vector<int>>& adj, vector<int>& vis_nodes, int start) {
        queue<pair<int, int>> q;
        q.push({start, 0});
        int max_path_len = 0;

        while (!q.empty()) {
            auto [curr_node, dist] = q.front();
            q.pop();

            for (int ngbr : adj[curr_node]) {
                if (vis_nodes[ngbr] == -1) {
                    q.push({ngbr, dist + 1});
                    vis_nodes[ngbr] = 1;
                    max_path_len = max(dist + 1, max_path_len);
                }
            }
        }
        return max_path_len;
    }

    int maximumInvitations(vector<int>& fav) {
        int n = fav.size();
        unordered_map<int, vector<int>> adj;

        // Reverse the graph
        for (int u = 0; u < n; u++) {
            int v = fav[u];
            adj[v].push_back(u);
        }

        int longest_cycle = 0;
        int longest_happy_couple = 0;
        vector<int> vis(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] == -1) {
                unordered_map<int, int> mp;
                int curr_node = i;
                int curr_node_count = 0;

                // Traverse to detect cycles
                while (vis[curr_node] == -1) {
                    vis[curr_node] = 1;
                    mp[curr_node] = curr_node_count;
                    int next_node = fav[curr_node];
                    curr_node_count++;

                    if (mp.count(next_node)) {
                        int cycle_len = curr_node_count - mp[next_node];
                        longest_cycle = max(longest_cycle, cycle_len);

                        // Handle cycles of length 2 (happy couples)
                        if (cycle_len == 2) {
                            vector<int> vis_nodes(n, -1);
                            vis_nodes[curr_node] = 1;
                            vis_nodes[fav[curr_node]] = 1;

                            longest_happy_couple += 2 +
                                bfs(adj, vis_nodes, curr_node) +
                                bfs(adj, vis_nodes, fav[curr_node]);
                        }
                        break;
                    }
                    curr_node = next_node;
                }
            }
        }
        return max(longest_happy_couple, longest_cycle);
    }
};
