class Solution {
public:
    string pushDominoes(string dom) {
        int n = dom.size();
        vector<int> left_se_R(n, -1);
        vector<int> right_se_L(n, -1);
        
        // Fill nearest R to the left
        for (int i = 0; i < n; ++i) {
            if (dom[i] == 'L') {
                left_se_R[i] = -1;
            } 
            else if (dom[i] == 'R') {
                left_se_R[i] = i;
            } else if (i > 0) {
                left_se_R[i] = left_se_R[i - 1];
            }
        }

        // Fill nearest L to the right
        for (int i = n - 1; i >= 0; --i) {
            if (dom[i] == 'R') {
                right_se_L[i] = -1;
            } 
            else if (dom[i] == 'L') {
                right_se_L[i] = i;
            } else if (i < n - 1) {
                right_se_L[i] = right_se_L[i + 1];
            }
        }

        string ans(n, '.');
        for (int i = 0; i < n; ++i) {
            int l = left_se_R[i];
            int r = right_se_L[i];
            if (l == -1 && r == -1) {
                ans[i] = dom[i];  // preserve original state if untouched
            } else if (l == -1) {
                ans[i] = 'L';
            } else if (r == -1) {
                ans[i] = 'R';
            } else {
                int distL = abs(i - l);
                int distR = abs(r - i); // since r > i
                if (distL == distR) ans[i] = '.';
                else if (distL < distR) ans[i] = 'R';
                else ans[i] = 'L';
            }
        }

        return ans;
    }
};