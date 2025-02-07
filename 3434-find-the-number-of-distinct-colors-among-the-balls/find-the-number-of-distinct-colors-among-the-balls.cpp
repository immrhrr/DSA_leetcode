class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& q) {
        int n=q.size();
        vector<int>ans(n,0);
        unordered_map<int,int>ball_color;
        unordered_map<int,int>color_ball;
        for(int i=0;i<n;i++){
            int ball=q[i][0];
            int color=q[i][1];
            if(ball_color.find(ball)==ball_color.end()){
                color_ball[color]++;
            }
            else{
                int old_col=ball_color[ball];
                color_ball[old_col]--;
                if(color_ball[old_col]==0){
                    color_ball.erase(old_col);
                }
                color_ball[color]++;
            }
            ball_color[ball]=color;
            ans[i]=color_ball.size();
        }
        return ans;
    }
};