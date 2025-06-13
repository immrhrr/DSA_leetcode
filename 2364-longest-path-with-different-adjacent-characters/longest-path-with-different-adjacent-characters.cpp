class Solution {
public:
    int ans = 1;

    int dfs(vector<vector<int>>& adj, int src, int parent, string& s) {
        int longest = 0, secondLongest = 0;

        for (int ngbr : adj[src]) {
            if (ngbr == parent||ngbr==src) continue;  // fix here

            int childLen = dfs(adj, ngbr, src, s);

            if (s[ngbr] == s[src]) continue;  // skip same character edges

            if (childLen > longest) {
                secondLongest = longest;
                longest = childLen;
            } else if (childLen > secondLongest) {
                secondLongest = childLen;
            }
        }

        // Update max answer
        int koi_ek=max(longest,secondLongest)+1;
        int root=1;
        int neeche=longest+secondLongest+1;
        ans=max({ans,koi_ek,neeche,root});
        return max({koi_ek,root});
        
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; ++i) {
            adj[i].push_back(parent[i]);
            adj[parent[i]].push_back(i);
        }

        dfs(adj, 0, -1, s);
        return ans;
    }
};
