class Solution {
public:
    int solve(vector<int>&arr){
        int n=arr.size();
        int cnt=0;
        int curr=0;
        for(int i=0;i<n;i++){
            if(arr[i]==1){
                curr++;
                cnt+=curr;
            }
            else{
                curr=0;
            }
        }
        return cnt;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int result=0;
        for(int startRow=0;startRow<n;startRow++){
            vector<int>arr(m,1);
            for(int endRow=startRow;endRow<n;endRow++){
                for(int col=0;col<m;col++){
                    arr[col]=arr[col]&mat[endRow][col];
                }
                result+=solve(arr);
            }
        }
        return result;
    }
};