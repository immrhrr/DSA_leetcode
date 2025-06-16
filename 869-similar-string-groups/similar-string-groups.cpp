class Solution {
public:
    bool is_similar(string&s1,string&s2){
        int n=s1.size();
        if(s1==s2)return true;
        int mistake=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                mistake++;
            }
        }
        return (mistake==2);
    }
    void dfs(vector<vector<int>>&adj,int src,vector<bool>&vis){
        vis[src]=true;
        for(int i=0;i<adj[src].size();i++){
            int ngbr=adj[src][i];
            if(!vis[ngbr]){
                vis[ngbr]=true;
                dfs(adj,ngbr,vis);
            }
        }
        return;
    }
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(is_similar(strs[i],strs[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n,false);
        int groups=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,i,vis);
                groups++;
            }
        }
        return groups;
    }
};