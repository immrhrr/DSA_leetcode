class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        if(n==1||n==0)return 0;
        set<pair<int,int>>st;
        queue<pair<int,int>>q;
        int need=0;
        for(int i=0;i<n;i++){
            q.push({i,pow(2,i)});
            st.insert({i,pow(2,i)});
            need=need|(1<<i);
        }
        int ans=0;
        while(!q.empty()){
            int m=q.size();
            while(m--){
                auto it=q.front();
                q.pop();
                int node=it.first;
                int mask=it.second;
                if(mask==need)return ans;
                for(int i=0;i<graph[node].size();i++){
                    int ngbr=graph[node][i];
                    int temp=pow(2,ngbr);
                    if(st.find({ngbr,temp|mask})==st.end()){
                        st.insert({ngbr,temp|mask});
                        q.push({ngbr,temp|mask});
                    }
                }
            }
             ans++;
        }
        return ans;
    }
};