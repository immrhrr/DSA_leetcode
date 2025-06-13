class Solution {
public:
    int bfs(vector<vector<int>>&adj,int src){
        queue<int>q;
        int n=adj.size();
        q.push(src);
        vector<bool>vis(n,false);
        vis[src]=true;
        int cnt=0;
        while(!q.empty()){
            int curr=q.front();
            cnt++;
            q.pop();
            for(int i=0;i<adj[curr].size();i++){
                int ngbr=adj[curr][i];
                if(!vis[ngbr]){
                    vis[ngbr]=true;
                    q.push(ngbr);
                }
            }
        }
        return cnt;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        //we have to find the max no of nodes that 
        //can be visited from any one source node
        //only thing is here how to make the adj list
        int n=bombs.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                long long x1=bombs[i][0];
                long long y1=bombs[i][1];
                long long r1=bombs[i][2];

                long long x2=bombs[j][0];
                long long y2=bombs[j][1];
                long long r2=bombs[j][2];

                long long dist=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
                long long temp=(long long)r1*r1;
                if(temp>=dist){
                    adj[i].push_back(j);
                }

            }
        }int cnt=1;
        for(int i=0;i<n;i++){
            int curr=bfs(adj,i);
            cnt=max(cnt,curr);
        }
        return cnt;
    }
};