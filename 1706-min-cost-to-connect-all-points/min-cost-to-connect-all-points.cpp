class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];
                int x2=points[j][0];
                int y2=points[j][1];
                int d=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>vis(n,false);
        pq.push({0,0});
        int ans=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int p=it.second;
            if(vis[p])continue;
            vis[p]=true;
            ans+=d;
            for(int i=0;i<adj[p].size();i++){
                int ngbr=adj[p][i].first;
                int dist=adj[p][i].second;
                if(vis[ngbr]==false){
                    pq.push({dist,ngbr});
                }
            }
        }
        return ans;
    }
};