class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int tot = 0;

        // Track two smallest numbers with remainder 1 and remainder 2
        int r1_min1 = INT_MAX, r1_min2 = INT_MAX;
        int r2_min1 = INT_MAX, r2_min2 = INT_MAX;

        for (int x : nums) {
            tot += x;
            int r = x % 3;
            if (r == 1) {
                if (x < r1_min1) {
                    r1_min2 = r1_min1;
                    r1_min1 = x;
                } else if (x < r1_min2) {
                    r1_min2 = x;
                }
            } else if (r == 2) {
                if (x < r2_min1) {
                    r2_min2 = r2_min1;
                    r2_min1 = x;
                } else if (x < r2_min2) {
                    r2_min2 = x;
                }
            }
        }

        if (tot % 3 == 0) return tot;

        int ans = 0;
        if (tot % 3 == 1) {
            // remove one r=1 OR two r=2
            int remove1 = r1_min1;
            long remove2 = (r2_min1 == INT_MAX || r2_min2 == INT_MAX) 
                           ? INT_MAX 
                           : (long)r2_min1 + r2_min2;
            long bestRemove = min((long)remove1, remove2);
            if (bestRemove == INT_MAX) return 0;
            ans = tot - (int)bestRemove;
        } else { // tot % 3 == 2
            // remove one r=2 OR two r=1
            int remove1 = r2_min1;
            long remove2 = (r1_min1 == INT_MAX || r1_min2 == INT_MAX) 
                           ? INT_MAX 
                           : (long)r1_min1 + r1_min2;
            long bestRemove = min((long)remove1, remove2);
            if (bestRemove == INT_MAX) return 0;
            ans = tot - (int)bestRemove;
        }

        return ans;
    }
};
