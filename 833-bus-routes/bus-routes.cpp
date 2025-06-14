class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source,
                              int target) {
                                if(source==target)return 0;
        // total bus
        int n = routes.size();
        vector<bool> vis(n, false);
        // multi source bfs
        queue<int> q;
        // bus_stand i ko kaun kaunsa bus se jaa skte hain uska index
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                // bus i se bus_stand j jaa skte hain
                mp[routes[i][j]].push_back(i);

                if (routes[i][j] == source) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        // at the start q will store kaun kaunsa bus se hum journey start kar
        // stke hain
        int ans = 1;
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                int curr_bus = q.front();
                q.pop();
                for (int i = 0; i < routes[curr_bus].size(); i++) {
                    int bus_stand = routes[curr_bus][i];
                    if (bus_stand == target)
                        return ans;
                    for (auto it : mp[bus_stand]) {
                        if (vis[it] == false) {
                            vis[it] = true;
                            q.push(it);
                        }
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};