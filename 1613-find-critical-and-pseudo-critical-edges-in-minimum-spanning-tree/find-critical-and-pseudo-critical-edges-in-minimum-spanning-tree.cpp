class Solution {
public:
    int find(int a, vector<int>& parent) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a], parent);
    }

    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA == rootB) return;
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootB] > rank[rootA]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
    }
    static bool comp(vector<int>&e1,vector<int>&e2){
        int w1=e1[2];
        int w2=e2[2];
        return w1<w2;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<vector<int>>arr;
        arr=edges;
        vector<int> parent(n), rank(n, 0);
        iota(parent.begin(), parent.end(), 0);
        int m=edges.size();
        int mst=0;
        for(int i=0;i<m;i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),comp);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            if(find(u,parent)!=find(v,parent)){
                mst+=wt;
                Union(u,v,parent,rank);
            }
        }
        
        vector<int>critical;
        vector<int>pseudo;
        vector<bool>vis(m,false);
        for(int i=0;i<m;i++){
            int temp=0;
            int cnt=0;
            vector<int> parent(n), rank(n, 0);
            iota(parent.begin(), parent.end(), 0);
            for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            int ind=edges[j][3];
            if(i==ind){
                continue;
            }
            if(find(u,parent)!=find(v,parent)){
                temp+=wt;
                Union(u,v,parent,rank);
                cnt++;
            }
            }
            if(cnt<n-1||temp>mst){
                critical.push_back(i);
                 vis[i]=true;
            }
        }
        
        for(int i=0;i<m;i++){
            int temp=0;
            int cnt=0;
            vector<int> parent(n), rank(n, 0);
            iota(parent.begin(), parent.end(), 0);
            if(vis[i]==false){
            Union(arr[i][0],arr[i][1],parent,rank);
            cnt++;
            temp+=arr[i][2];
            }
            for(int j=0;j<m;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            int ind=edges[j][3];
            if(ind==i)continue;
            if(find(u,parent)!=find(v,parent)){
                temp+=wt;
                Union(u,v,parent,rank);
                cnt++;
            }
            }
            if(cnt==n-1&&temp==mst){
                pseudo.push_back(i);
                vis[i]=true;
            }
        }

        vector<vector<int>>ans(2);
        ans[0]=critical;
        ans[1]=pseudo;
        return ans;
    }
};