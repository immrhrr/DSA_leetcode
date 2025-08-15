class Solution {
public:
    // Custom comparator: sort by length asc, width desc
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        // Step 1: sort envelopes
        sort(env.begin(), env.end(), comp);

        // Step 2: Extract widths
        vector<int> widths;
        widths.reserve(n);
        for (auto &e : env) {
            widths.push_back(e[1]);
        }

        // Step 3: LIS on widths using binary search
        vector<int> lis;
        for (int w : widths) {
            auto it = lower_bound(lis.begin(), lis.end(), w);
            if (it == lis.end()) {
                lis.push_back(w);
            } else {
                *it = w; // replace to keep sequence minimal
            }
        }
        return lis.size();
    }
};
