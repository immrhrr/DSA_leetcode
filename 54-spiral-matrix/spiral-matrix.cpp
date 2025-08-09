class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0;
        int bottom=matrix.size()-1;
        int left=0;
        int right=matrix[0].size()-1;
        vector<int>ans;
        int id=0;
        while(left<=right&&top<=bottom){
            //left to right
            //constant=top
            if(id==0){
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
            }
            //top to bottom
            //constant=right
            if(id==1){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
            }
            //right to left
            //constant=bottom
            if(id==2){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            //bottom to top
            //constant=left
            if(id==3){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
            id=(id+1)%4;
        }
        return ans;

        
    }
};