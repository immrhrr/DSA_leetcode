class Solution {
public:
    int ans = -1;
    void dfs(vector<int>& edges, vector<bool>& vis, vector<bool>& in_Rec,vector<int>& count, int curr) {
        vis[curr] = true;
        in_Rec[curr] = true;
        int ngbr = edges[curr];
        if (ngbr != -1) {
            if (!vis[ngbr]) {
                count[ngbr] = count[curr] + 1;
                dfs(edges, vis, in_Rec, count, ngbr);
            } else if (in_Rec[ngbr]) {
                ans = max(ans, count[curr] - count[ngbr] + 1);
            }
        }
        in_Rec[curr] = false;
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, false);
        vector<bool> in_Rec(n, false);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++) {
            if (vis[i] == false) {
                dfs(edges, vis, in_Rec, count, i);
            }
        }
        return ans;
    }
};