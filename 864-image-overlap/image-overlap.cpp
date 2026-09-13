class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=0;
        for(int row_off=-n+1;row_off<n;row_off++){
            for(int col_off=-n+1;col_off<n;col_off++){
                int cnt=0;
                for(int row=0;row<n;row++){
                    for(int col=0;col<n;col++){
                        int nrow=row+row_off;
                        int ncol=col+col_off;
                        if(nrow>=0&&nrow<n&&ncol>=0&&ncol<n){
                            if(img1[row][col]==1&&img2[nrow][ncol]==1){
                                cnt++;
                            }
                        }

                    }
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};