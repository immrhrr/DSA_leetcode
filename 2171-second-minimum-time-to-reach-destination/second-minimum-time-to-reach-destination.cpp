class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<int>d1(n+1,1e9);
        vector<int>d2(n+1,1e9);
        vector<vector<int>>adj(n+1);
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //time,node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        d1[1]=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time_pass=it.first;
            int curr=it.second;
            int div=time_pass/change;
            if(div%2==1){
                time_pass=(div+1)*change;
            }
            
            for(int i=0;i<adj[curr].size();i++){
                int ngbr=adj[curr][i];
                int next_time=time_pass+time;
                if(d1[ngbr]>next_time){
                    d2[ngbr]=d1[ngbr];
                    d1[ngbr]=next_time;
                    pq.push({next_time,ngbr});
                }
                else if(d2[ngbr]>next_time&&next_time!=d1[ngbr]){
                    d2[ngbr]=next_time;
                    pq.push({next_time,ngbr});
                }
               
            }

        }
        return d2[n];
        
    }
};