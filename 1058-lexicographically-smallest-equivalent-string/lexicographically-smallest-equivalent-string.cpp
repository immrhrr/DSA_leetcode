class Solution {
public:
    void dfs(vector<vector<int>>&adj,int src,int& ans,vector<bool>&vis){
        vis[src]=true;
        for(int i=0;i<adj[src].size();i++){
            if(vis[adj[src][i]]){
                continue;
            }
            ans=min(ans,adj[src][i]);
            vis[adj[src][i]]=true;
            dfs(adj,adj[src][i],ans,vis);
        }
        return;

    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n=s1.size();
        int m=baseStr.size();
        vector<vector<int>>adj(26);
        for(int i=0;i<n;i++){
            int a=s1[i]-'a';
            int b=s2[i]-'a';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        string ans=baseStr;
        for(int i=0;i<m;i++){
            char ch=baseStr[i];
            int src=ch-'a';
            int temp=src;
            vector<bool>vis(26,false);
            dfs(adj,src,temp,vis);
            ans[i]=temp+'a';
        }
        return ans;
    }
};