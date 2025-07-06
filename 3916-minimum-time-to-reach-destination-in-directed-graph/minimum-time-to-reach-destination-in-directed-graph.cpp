class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n==1)return 0;
        vector<vector<pair<int,pair<int,int>>>>adj(n);
        vector<int>samay(n,INT_MAX);
        samay[0]=0;
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int start=it[2];
            int end=it[3];
            adj[u].push_back({v,{start,end}});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int time=top.first;
            int node=top.second;
            if(node==n-1)return time;
            if(samay[node]<time){
                continue;
            }
            for(int i=0;i<adj[node].size();i++){
                int ngbr=adj[node][i].first;
                int kab_se=adj[node][i].second.first;
                int kab_tak=adj[node][i].second.second;
                //window time over
                if(time>kab_tak){
                    continue;
                }
                else if(time<=kab_se){
                    if(samay[ngbr]>kab_se+1){
                    samay[ngbr]=kab_se+1;
                    pq.push({samay[ngbr],ngbr});
                    }   
                }
                else if(time>kab_se&&samay[ngbr]>time+1){
                    samay[ngbr]=time+1;
                    pq.push({samay[ngbr],ngbr}); 
                }
            }
        }
        return -1;
    }
};
//we have to start in between kab_se. to kab_tak but we will take one unit time