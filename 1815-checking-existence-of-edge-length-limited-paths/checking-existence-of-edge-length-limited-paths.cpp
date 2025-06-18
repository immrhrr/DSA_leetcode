class Solution {
public:
    static bool customSort(const vector<int>& temp1, const vector<int>& temp2) {
        int x = temp1[2];
        int y = temp2[2];
        return x < y;
    }
    static bool lambda(const vector<int>& temp1, const vector<int>& temp2) {
        return temp1[2] < temp2[2];
    }
    int find(int a, vector<int>& parent) {
        if (parent[a] == a)
            return a;
        return parent[a] = find(parent[a], parent);
    }
    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA == rootB)
            return;
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootB] > rank[rootA]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge,
                                           vector<vector<int>>& q) {
        vector<int> parent(n, 0);
        iota(parent.begin(), parent.end(), 0);
        vector<int> rank(n, 0);
        int m = q.size();
        for (int i = 0; i < m; i++) {
            q[i].push_back(i);
        }
        sort(q.begin(), q.end(), customSort);
        sort(edge.begin(), edge.end(), lambda);
        vector<bool> ans(m, false);
        int ind = 0;
        for (int i = 0; i < m; i++) {
            int limit = q[i][2];
            int src = q[i][0];
            int dst = q[i][1];
            int index = q[i][3];
            while (ind < edge.size() && edge[ind][2] < limit) {
                Union(edge[ind][0], edge[ind][1], parent, rank);
                ind++;
            }

            if (find(src, parent) == find(dst, parent)) {
                ans[index] = true;
            }
        }
        return ans;
    }
};