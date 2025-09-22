class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> frq(101, 0);
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            frq[nums[i]]++;
            maxi = max(maxi, frq[nums[i]]);
        }
        int ans = 0;
        for (int i = 0; i < 101; i++) {
            if (frq[i] == maxi) {
                ans += maxi;
            }
        }
        return ans;
    }
};