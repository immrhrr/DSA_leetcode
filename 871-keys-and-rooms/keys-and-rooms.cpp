class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        int temp=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:rooms[curr]){
                if(vis[it]==false){
                    vis[it]=true;
                    temp++;
                    q.push(it);
                }
            }
        }
        return temp==n;

        
    }
};