class Solution {
public:
    int find(int x) {
        string given = to_string(x);
        reverse(given.begin(), given.end());
        return stoi(given);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        unordered_map<int, int> expected_vals;
        for (int j = 0; j < n; j++) {
            if (expected_vals.find(nums[j]) != expected_vals.end()) {
                ans = min(ans, j - expected_vals[nums[j]]);
            }
            int rev = find(nums[j]);
            expected_vals[rev] = j;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};