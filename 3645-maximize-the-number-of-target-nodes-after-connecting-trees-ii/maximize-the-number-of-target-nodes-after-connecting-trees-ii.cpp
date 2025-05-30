class Solution {
public:
//dfs(adj1,0,vis1,temp1,true);
    void dfs(vector<vector<int>>& adj, int src, vector<bool>& vis,vector<int>&temp,bool flag) {
       
        for (int neighbor : adj[src]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                temp[neighbor]=!flag;
                dfs(adj, neighbor,vis,temp,!flag);
            }
        }
        return;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // First, determine the actual number of nodes
        int maxNode1 = 0, maxNode2 = 0;
        for (auto& e : edges1) {
            maxNode1 = max({maxNode1, e[0], e[1]});
        }
        for (auto& e : edges2) {
            maxNode2 = max({maxNode2, e[0], e[1]});
        }

        // Build adjacency lists
        vector<vector<int>> adj1(maxNode1 + 1);
        vector<vector<int>> adj2(maxNode2 + 1);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> result1(maxNode1 + 1, 0);  
        vector<int> result2(maxNode2 + 1, 0);
        vector<int> temp1(maxNode1 + 1, 0);  
        vector<int> temp2(maxNode2 + 1, 0);
        vector<bool> vis1(maxNode1 + 1, false);  
        vector<bool> vis2(maxNode2 + 1, false);
        dfs(adj1,0,vis1,temp1,true);
        dfs(adj2,0,vis2,temp2,true);
        
        int zero1=0;
        int one1=0;
        for (int src = 0; src <= maxNode1; src++) {
           if(temp1[src]==0)zero1++;
           else one1++;
        }

        int zero2=0;
        int one2=0;
        for (int src = 0; src <= maxNode2; src++) {
           if(temp2[src]==0)zero2++;
           else one2++;
        }
        
        for (int src = 0; src <= maxNode1; src++) {
            if(temp1[src]==0){
                result1[src]=zero1;
            }
            else
            result1[src]=one1;
        }

        for (int src = 0; src <= maxNode2; src++) {
            if(temp2[src]==0){
                result2[src]=one2;
            }
            else
            result2[src]=zero2;
        }

        int maxi = *max_element(result2.begin(), result2.end());

        for (int i = 0; i < result1.size(); i++) {
            result1[i] += maxi;
        }

        return result1;
        
    }
};

