class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>>adj(26,vector<long long>(26,1e9));
        int n=source.size();
        int m=original.size();
        int s=0;int t=0;long long paisa=0;
        for(int i=0;i<m;i++){
            s=original[i]-'a';
            t=changed[i]-'a';
            paisa=cost[i];
            adj[s][t]=min(paisa,adj[s][t]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(adj[i][j]>adj[i][k]+adj[k][j]){
                        adj[i][j]=adj[i][k]+adj[k][j];
                    }
                }
            }
        }
        long long ans=0;
        
        for(int i=0;i<n;i++){
            if(source[i]==target[i]){
                continue;
            }
            if(adj[source[i]-'a'][target[i]-'a']==1e9){
                return -1;
            }
            ans+=adj[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};