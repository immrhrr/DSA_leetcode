class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        ans.reserve(n * m); // optional, avoids repeated reallocations

        int i = 0, j = 0;
        bool goingUp = true;

        while (ans.size() < n * m) {
            ans.push_back(mat[i][j]);

            if (goingUp) {
                if (j == m - 1) {      // hit last column
                    i++; 
                    goingUp = false;
                } else if (i == 0) {   // hit first row
                    j++;
                    goingUp = false;
                } else {               // move up-right
                    i--;
                    j++;
                }
            } else { // going down
                if (i == n - 1) {      // hit last row
                    j++;
                    goingUp = true;
                } else if (j == 0) {   // hit first column
                    i++;
                    goingUp = true;
                } else {               // move down-left
                    i++;
                    j--;
                }
            }
        }

        return ans;
    }
};
