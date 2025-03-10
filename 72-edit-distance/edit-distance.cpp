class Solution {
public:
    int minDistance(string w1, string w2) {
        int n1 = w1.size();
        int n2 = w2.size();

        vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);

        // Base case: Filling the first row (i == 0)
        for (int j = 0; j <= n2; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n1; i++) {
            curr[0] = i;  // Base case: when w2 is empty, cost = i (delete all from w1)
            for (int j = 1; j <= n2; j++) {
                if (w1[i - 1] == w2[j - 1]) {
                    curr[j] = prev[j - 1];  // Characters match, no operation needed
                } else {
                    curr[j] = 1 + min({prev[j - 1], prev[j], curr[j - 1]});  
                    // Replace (prev[j - 1]), Delete (prev[j]), Insert (curr[j - 1])
                }
            }
            prev = curr;  // Move current row to previous row
        }

        return prev[n2];  // Final result
    }
};
