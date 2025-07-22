class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, maxSum = 0;

        while (j < n) {
            while (seen.count(nums[j])) {
                seen.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
            seen.insert(nums[j]);
            sum += nums[j];
            maxSum = max(maxSum, sum);
            j++;
        }

        return maxSum;
    }
};
