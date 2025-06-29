class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1e9 + 7;

        vector<int> pow2(n, 1);
        for (int i = 1; i < n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int limit = target - nums[i];
            if (limit < nums[i]) break; 

            int left = i, right = n - 1, ind = -1;
           
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] <= limit) {
                    ind = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (ind != -1 && ind >= i) {
                int count = ind - i;
                ans = (ans + pow2[count]) % mod;
            }
        }

        return ans;
    }
};
