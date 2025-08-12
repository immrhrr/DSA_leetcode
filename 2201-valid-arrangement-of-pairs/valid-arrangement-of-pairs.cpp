class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        unordered_map<int, int> in, out;

        for (auto &p : pairs) {
            int u = p[0], v = p[1];
            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }

        // Choose start node
        int start = pairs[0][0]; // default start
        for (auto &[node, _] : adj) {
            if (out[node] - in[node] == 1) {
                start = node;
                break;
            }
        }

        // Hierholzer’s algorithm
        stack<int> st;
        vector<int> temp;
        st.push(start);

        while (!st.empty()) {
            int curr = st.top();
            if (!adj[curr].empty()) {
                int next = adj[curr].back();
                adj[curr].pop_back();
                st.push(next);
            } 
            //when there is nothing left to visit then put in the temp
            else {
                temp.push_back(curr);
                st.pop();
            }
        }

        reverse(temp.begin(), temp.end()); // get correct path order

        // Build edges from the path
        vector<vector<int>> ans;
        for (int i = 1; i < temp.size(); i++) {
            ans.push_back({temp[i - 1], temp[i]});
        }

        return ans;
    }
};
