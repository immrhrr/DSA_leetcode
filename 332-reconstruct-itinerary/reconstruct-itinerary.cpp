class Solution {
public:
    unordered_map<string,priority_queue<string,vector<string>,greater<string>>>adj;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto &t:tickets){
            string u=t[0];
            string v=t[1];
            adj[u].push(v);
        }
        stack<string>st;
        st.push("JFK");
        vector<string>ans;
        while(!st.empty()){
            string curr=st.top();
            if(adj[curr].size()==0){
                ans.push_back(curr);
                st.pop();
            }
            else{
                string nxt=adj[curr].top();
                adj[curr].pop();
                st.push(nxt);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};