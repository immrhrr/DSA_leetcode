class Solution {
public:
    void dfs(vector<int>&edges,int src,vector<int>&d){
        if(edges[src]==-1)return;
        if(d[edges[src]]!=1e9)return;
        d[edges[src]]=min(d[edges[src]],d[src]+1);
        dfs(edges,edges[src],d);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int>dist1(n,1e9);
        vector<int>dist2(n,1e9);
        dist1[node1]=0;
        dist2[node2]=0;
        dfs(edges,node1,dist1);
        dfs(edges,node2,dist2);
        int dist=1e9;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(dist1[i]==1e9||dist2[i]==1e9)continue;
            if(max(dist1[i],dist2[i])<dist){
                dist=max(dist1[i],dist2[i]);
                ind=i;
            }
        }
        return ind;
    }
};