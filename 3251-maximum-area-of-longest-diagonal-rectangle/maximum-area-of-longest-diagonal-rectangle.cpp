class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        int n=dim.size();
        int area=0;
        int d=0;
        for(int i=0;i<n;i++){
            int temp_d=dim[i][0]*dim[i][0]+dim[i][1]*dim[i][1];
            if(temp_d>d){
                area=dim[i][0]*dim[i][1];
                d=temp_d;
            }
            if(temp_d==d){
                area=max(area,dim[i][0]*dim[i][1]);
            }
        }
        return area;
    }
};