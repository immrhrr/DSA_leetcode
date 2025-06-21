class Solution {
public:
    int solve(vector<int> arr, int limit) {
        int n = arr.size();
        int low = 0;
        int high = n - 1;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > limit) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    int minimumDeletions(string word, int k) {
        int n = word.size();
        vector<int> frq(26, 0);
        for (int i = 0; i < n; i++) {
            frq[word[i] - 'a']++;
        }
        sort(frq.begin(), frq.end());
        vector<int> temp;
        for (int i = 0; i < 26; i++) {
            if (frq[i] != 0) {
                temp.push_back(frq[i]);
            }
        }
        if (temp.size() == 1)
            return 0;
        if (temp[temp.size() - 1] - temp[0] <= k)
            return 0;
        int m = temp.size();
        vector<int> pref(m);
        pref[0] = temp[0];
        for (int i = 1; i < m; i++) {
            pref[i] = pref[i - 1] + temp[i];
        }
        int ans = INT_MAX;
        for (int i = 0; i < m; i++) {
            //left side to remove
            int curr = pref[i] - temp[i];
            int limit = temp[i] + k;
            // first index which is having val bigger than limit
            int index = solve(temp, limit);
            //right side to remove
            if (index != -1) {
                int actual = (index == 0) ? pref[m - 1] : (pref[m - 1] - pref[index - 1]);

                //int actual = pref[m - 1] - pref[index] + temp[index];
                int expected = (m- index)* limit;
                 curr += (actual - expected);
            }

            ans = min(ans, curr);
        }
        return ans;
    }
};