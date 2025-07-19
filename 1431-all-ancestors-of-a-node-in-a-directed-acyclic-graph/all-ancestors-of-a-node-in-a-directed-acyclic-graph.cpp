class Solution {
public:
    void bfs(int src,vector<vector<int>>&ans,vector<vector<int>>&adj){
        //src se kaha kaha ja sakte hain
        queue<int>q;
        q.push(src);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                int ngbr=adj[curr][i];
                //matlab ki src se ngbr tak ja skte hain
                //ngbr ka ans mein src ko daalo
                if(ans[ngbr].size()>0&&ans[ngbr].back()==src){
                    continue;
                }
                ans[ngbr].push_back(src);
                q.push(ngbr);
            }
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        vector<vector<int>>ans(n);
        for(int src=0;src<n;src++){
            bfs(src,ans,adj);
        }
        return ans;
    }
};