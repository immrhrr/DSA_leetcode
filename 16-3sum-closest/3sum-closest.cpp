class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int ans = -1;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            while (right > left) {
                int curr = nums[i] + nums[left] + nums[right];
                if (abs(target - curr) < diff) {
                    diff = abs(target - curr);
                    ans = curr;
                }
                if (curr > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};