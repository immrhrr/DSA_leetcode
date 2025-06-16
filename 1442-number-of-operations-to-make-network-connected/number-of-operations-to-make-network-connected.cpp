class Solution {
public:
    int find(int i, vector<int>& parent) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i], parent);
    }
    void Union(int a, int b, vector<int>& parent, vector<int>& rank) {
        int rootA = find(a, parent);
        int rootB = find(b, parent);
        if (rootA == rootB)
            return;
        if (rank[rootA] > rank[rootB]) {
            parent[rootB] = rootA;
        } else if (rank[rootB] > rank[rootA]) {
            parent[rootA] = rootB;
        } else {
            parent[rootA] = rootB;
            rank[rootB]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1)return -1;
        vector<int>parent(n,0);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        //ans is number of group - 1;
        int group=0;
        int extra=0;
        for(int i=0;i<m;i++){
            int a=connections[i][0];
            int b=connections[i][1];
            if(find(a,parent)==find(b,parent)){
                extra++;
            }
            else{
                Union(a,b,parent,rank);
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                group++;
            }
        }
        return group-1;
    }
};