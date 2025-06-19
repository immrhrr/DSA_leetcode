class Solution {
public:
    double dfs(unordered_map<string,vector<pair<string,double>>>adj,string src,string&dst,unordered_set<string>&vis){
        if(src==dst)return 1.0;
        vis.insert(src);
        for(int i=0;i<adj[src].size();i++){
            string ngbr=adj[src][i].first;
            double val=adj[src][i].second;
            if(vis.find(ngbr)==vis.end()){
                vis.insert(ngbr);
                double res=dfs(adj,ngbr,dst,vis);
                if(res!=-1.0){
                    return res*val;
                }
                }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& q) {
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>>adj;
        for(int i=0;i<n;i++){
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        int m=q.size();
        vector<double>ans(m);
        for(int i=0;i<m;i++){
            string src=q[i][0];
            string dst=q[i][1];
            ans[i]=-1.0;
            if(adj.find(src)!=adj.end()){
                unordered_set<string>vis;
                ans[i]= dfs(adj,src,dst,vis);
            }
        }
        return ans;
    }
};