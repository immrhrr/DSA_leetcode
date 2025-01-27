class Solution {
public: 

    bool dfs(unordered_map<int,vector<int>>&adj,int curr,int &dest,vector<bool>&visited){
        visited[curr]=true;
        if(dest==curr){
            return true;
        }
        bool flag=false;
        for(int i=0;i<adj[curr].size();i++){
            if(flag){
                return true;
            }
            int temp=adj[curr][i];
             if(dest==temp){
            return true;
        }
            if(visited[temp]==false){
                flag=flag||dfs(adj,temp,dest,visited);
                visited[curr]=true;
            }

        }
        return flag;

    }
    vector<bool> checkIfPrerequisite(int num, vector<vector<int>>& pre, vector<vector<int>>& q) {
        int m=q.size();
        vector<bool>ans(m,false);
        int n=pre.size();
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<n;i++){
            int u=pre[i][0];
            int v=pre[i][1];
            adj[u].push_back(v);
        }
        for(int i=0;i<m;i++){
            int curr=q[i][0];
            int dest=q[i][1];
            vector<bool>visited(num,false);
            if(dfs(adj,curr,dest,visited)){
                ans[i]=true;
            }
        }
        return ans;

    }
};