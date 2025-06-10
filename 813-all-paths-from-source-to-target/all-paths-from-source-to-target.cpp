class Solution {
public:
    void dfs(int src, vector<vector<int>>& graph, vector<vector<int>>& ans,vector<int> curr) {
        int n = graph.size();
        curr.push_back(src);
        if (src == n - 1) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < graph[src].size(); i++) {
            int ngbr = graph[src][i];
            dfs(ngbr, graph, ans, curr);
        }
        curr.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(0, graph, ans, curr);
        return ans;
    }
};