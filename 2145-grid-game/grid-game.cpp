#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        long long top=0;
        for (int i = 0; i < n; i++) {
           top+=grid[0][i];
        }
        
        long long ans = LLONG_MAX;
        long long temp = 0;
        
        for (int i = 0; i < n; i++) {
            // Maximum points the opponent can collect after choosing column i
           top=top-grid[0][i];
            long long bottom = temp;
            ans = min(ans, max(top, bottom));
            temp += grid[1][i];
        }
        
        return ans;
    }
};
