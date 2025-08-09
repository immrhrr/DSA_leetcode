class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>adj(n);
        vector<int>inDegree(n);
        int m=pre.size();
        vector<int>temp;
        for(int i=0;i<m;i++){
            int a=pre[i][0];
            int b=pre[i][1];
            // b pehle phir a krna hai hume
            adj[b].push_back(a);
            inDegree[a]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0){
                q.push(i);
                temp.push_back(i);
            }
        }
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                int ngbr=adj[curr][i];
                inDegree[ngbr]--;
                if(inDegree[ngbr]==0){
                    q.push(ngbr);
                    temp.push_back(ngbr);
                }
            }
        }
        return temp.size()==n;
    }
};