class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for (int curr : st) {
            int cnt = 0;
            if (st.find(curr - 1) == st.end()) {
                while (st.find(curr) != st.end()) {
                    cnt++;
                    curr++;
                }
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
