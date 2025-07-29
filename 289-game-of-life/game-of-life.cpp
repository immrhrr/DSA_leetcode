class Solution {
public:
    int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                int life = 0;
                for (int k = 0; k < 8; k++) {
                    int nrow = row + dx[k];
                    int ncol = col + dy[k];
                    if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                        if (board[nrow][ncol] == 1||board[nrow][ncol] == -1) {
                            life++;
                        }
                    }
                }
                if (board[row][col] == 1) {
                    if (life < 2||life>3) {
                        //die karo
                        board[row][col]=-1;
                    } else if (life == 2 || life == 3) {
                        //alive rahega
                        board[row][col]=1;
                    } 
                }
                else{
                    if(life==3){
                        //alive karo
                        board[row][col]=2;
                    }
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(board[row][col]==-1){
                    board[row][col]=0;
                }
                if(board[row][col]==2){
                    board[row][col]=1;
                }
            }
        }
        return;
    }
};