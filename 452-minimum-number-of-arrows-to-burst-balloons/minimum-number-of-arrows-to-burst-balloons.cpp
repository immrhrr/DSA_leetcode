class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n=points.size();
        int arrow=1;
        int last_end=points[0][1];
        for(int i=1;i<n;i++){
            int start=points[i][0];
            int end=points[i][1];
            if(start<=last_end){
                last_end=min(last_end,end);
            }
            else{
                arrow++;
                last_end=end;
            }
        }
        return arrow;
    }
};