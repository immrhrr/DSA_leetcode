#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> a(n, 0), b(n, 0);
        
        // Prefix sums for the top and bottom rows
        a[0] = grid[0][0];
        b[0] = grid[1][0];
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + grid[0][i];
            b[i] = b[i - 1] + grid[1][i];
        }
        
        long long ans = LLONG_MAX;
        long long temp = 0;
        
        for (int i = 0; i < n; i++) {
            // Maximum points the opponent can collect after choosing column i
            long long top = a[n - 1] - a[i];
            long long bottom = temp;
            ans = min(ans, max(top, bottom));
            temp += grid[1][i];
        }
        
        return ans;
    }
};
