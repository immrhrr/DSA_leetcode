class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1]; // sort heights in descending order if widths are equal
        return a[0] < b[0];     // otherwise sort by width ascending
    }

    int helper(int w, vector<vector<int>>& temp) {
        int low = 0, high = temp.size() - 1;
        int ind = temp.size(); // default = insert at end

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (temp[mid][1] >= w) {
                ind = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ind;
    }

    int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end(), comp);

        vector<vector<int>> temp; // will store LIS on heights
        for (int i = 0; i < n; i++) {
            int w = env[i][1];
            if (temp.empty() || w > temp.back()[1]) {
                temp.push_back(env[i]);
            } else {
                int ind = helper(w, temp);
                temp[ind] = env[i];
            }
        }
        return temp.size();
    }
};
