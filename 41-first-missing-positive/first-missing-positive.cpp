class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool one_present = false;

        // Step 1: Check if 1 is present, and clean invalid values
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) one_present = true;
            if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        if (!one_present) return 1;

        // Step 2: Use index as a marker (negate value at that index)
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }

        // Step 3: First positive index means missing number
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }

        // All numbers 1..n are present
        return n + 1;
    }
};
