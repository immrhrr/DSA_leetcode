class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent);
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
    bool equationsPossible(vector<string>& equations) {
        vector<int> rank(26, 0);
        vector<int> parent(26, 0);
        for (int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        for (int i = 0; i < equations.size(); i++) {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if (equations[i][1] == '=') {
                Union(a, b, parent, rank);
            }
        }
        for (int i = 0; i < equations.size(); i++) {
            int a = equations[i][0] - 'a';
            int b = equations[i][3] - 'a';
            if (equations[i][1] != '=') {
                if (find(a, parent) == find(b, parent)) {
                    return false;
                }
            }
        }
        return true;
    }
};