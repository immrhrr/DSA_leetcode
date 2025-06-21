class Solution {
public:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a], parent);
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA == rootB) return;
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootB] > rank[rootA]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parentA(n + 1), parentB(n + 1), rankA(n + 1, 0), rankB(n + 1, 0);
        iota(parentA.begin(), parentA.end(), 0);
        iota(parentB.begin(), parentB.end(), 0);
        
        int used = 0;

        // Step 1: Use type 3 (common) edges first
        for (auto& e : edges) {
            if (e[0] == 3) {
                int u = e[1], v = e[2];
                if (find(u, parentA) != find(v, parentA)) {
                    Union(u, v, parentA, rankA);
                    Union(u, v, parentB, rankB);
                    used++;
                }
            }
        }

        // Step 2: Use type 1 (Alice only)
        for (auto& e : edges) {
            if (e[0] == 1) {
                int u = e[1], v = e[2];
                if (find(u, parentA) != find(v, parentA)) {
                    Union(u, v, parentA, rankA);
                    used++;
                }
            }
        }

        // Step 3: Use type 2 (Bob only)
        for (auto& e : edges) {
            if (e[0] == 2) {
                int u = e[1], v = e[2];
                if (find(u, parentB) != find(v, parentB)) {
                    Union(u, v, parentB, rankB);
                    used++;
                }
            }
        }

        // Step 4: Check if fully connected
        for (int i = 1; i <= n; ++i) {
            if (find(i, parentA) != find(1, parentA) || find(i, parentB) != find(1, parentB)) {
                return -1;
            }
        }

        return edges.size() - used;
    }
};
