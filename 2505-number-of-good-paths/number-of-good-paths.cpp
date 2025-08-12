class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] == x)
            return x;
       return parent[x] = find(parent[x]);
    }
    void Union(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (rank[root_a] > rank[root_b]) {
            parent[root_b] = root_a;
        } else if (rank[root_a] < rank[root_b]) {
            parent[root_a] = root_b;
        } else {
            parent[root_a] = root_b;
            rank[root_b]++;
        }
        return;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        unordered_map<int, vector<int>> adj;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // value to nodes
        map<int, vector<int>> temp;
        for (int i = 0; i < vals.size(); i++) {
            temp[vals[i]].push_back(i);
        }
        int res = n;
        vector<bool> active(n, false);
        for (auto it : temp) {
            int curr_val = it.first;
            //curr_val kaun kaunsa node pe hai woh arr mein stored hai
            vector<int> arr;
            arr = it.second;
            for (int i = 0; i < arr.size(); i++) {
                active[arr[i]] = true;
                for (int j = 0; j < adj[arr[i]].size(); j++) {
                    //u->arr[i]
                    //v->adj[arr[i]][j]
                    int ngbr = adj[arr[i]][j];
                    //agar active hai node v toh join them
                    if (active[ngbr]) {
                        Union(arr[i], adj[arr[i]][j]);
                    }
                }
                //u ko activate kar do ab 
               // active[arr[i]] = true;
            }
            vector<int> parent2;
            for (auto it : arr) {
                parent2.push_back(find(it));
            }
            sort(parent2.begin(), parent2.end());
            int sz = parent2.size();
            for (int j = 0; j < sz; j++) {
                long long cnt = 0;
                int curr_parent = parent2[j];
                while (j < sz && parent2[j] == curr_parent) {
                    j++;
                    cnt++;
                }
                j--;
                res += (cnt * (cnt - 1)) / 2;
            }
        }
        return res;
    }
};