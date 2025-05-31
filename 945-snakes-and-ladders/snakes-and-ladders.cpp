class Solution {
public:
    pair<int,int>get_cord(int num,int n){
        int rb=(n-1)-(num-1)/n;
        //left to right
        int col=(num-1)%n;
        //right to left
        if(n%2==0&&rb%2==0||n%2==1&&rb%2==1){
            col=(n-1)-col;
        }
        return{rb,col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        queue<int>q;
        q.push(1);
        int steps=0;
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        vis[n-1][0]=true;
        while(!q.empty()){
            int m=q.size();
            while(m--){
                int curr=q.front();
                q.pop();
                if(curr==n*n){
                    return steps;
                }
                for(int val=1;val<=6;val++){
                    int nxt=curr+val;
                    if(nxt>n*n)break;
                    auto cordi=get_cord(nxt,n);
                    int r=cordi.first;
                    int c=cordi.second;
                    if(vis[r][c]==true)continue;
                    if(board[r][c]==-1){
                        q.push(nxt);
                    }
                    else{
                        q.push(board[r][c]);
                    }
                    vis[r][c]=true;
                }
            }
            steps++;
        }
        return -1;
        
    }
};