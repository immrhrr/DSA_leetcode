class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n == 3) {
            return max(0LL, 1LL * (nums[0] - nums[1]) * nums[2]);
        }

        vector<int> temp(n, 0);
        temp[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            temp[i] = max(temp[i + 1], nums[i]);
        }
        long long ans = 0;
        int maxi = nums[0];
        long long tempo = nums[0] - nums[1];
        for (int i = 0; i < n - 2; i++) {
            maxi = max(maxi, nums[i]);
            tempo = max(tempo, 1ll * (maxi - nums[i + 1]));
            ans = max(ans, (long long)(tempo) * (long long)temp[i + 2]);
        }
        return ans;
    }
};