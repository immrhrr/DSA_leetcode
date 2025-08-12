class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    void dfs(string u) {
        auto &pq = adj[u];
        while (!pq.empty()) {
            string v = pq.top();
            pq.pop();
            dfs(v);
        }
        result.push_back(u);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build adjacency list with min-heap for lexicographic order
        for (auto &t : tickets) {
            adj[t[0]].push(t[1]);
        }

        dfs("JFK");
        reverse(result.begin(), result.end());
        return result;
    }
};
