class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        int n = arr.size();
        unordered_map<string, int> globalFreq;
        vector<unordered_set<string>> individual(n);

        // Step 1: Build global and individual substring maps
        for (int i = 0; i < n; ++i) {
            int len = arr[i].length();
            for (int start = 0; start < len; ++start) {
                string temp = "";
                for (int end = start; end < len; ++end) {
                    temp += arr[i][end];
                    if (individual[i].insert(temp).second) {
                        globalFreq[temp]++;
                    }
                    // individual[i].insert(temp);
                    // globalFreq[temp]++;
                }
            }
        }

        vector<string> ans(n);
        for (int i = 0; i < n; ++i) {
            string res = "";
            int minLen = INT_MAX;

            for (const string& s : individual[i]) {
                if (globalFreq[s] == 1) {
                    int slen = s.length();
                    if (slen < minLen || (slen == minLen && s < res)) {
                        res = s;
                        minLen = slen;
                    }
                }
            }

            ans[i] = res;
        }

        return ans;
    }
};
