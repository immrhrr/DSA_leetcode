class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // basically we want to find the max sum of a subarray which has all
        // unique elements
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        unordered_map<int, int> mp;
        int sum = 0;
        while (j < n) {
            sum += nums[j];
            if (mp.find(nums[j]) != mp.end()) {
                while (i < j && nums[i] != nums[j]) {
                    sum -= nums[i];
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                if (nums[i] == nums[j]) {
                    sum -= nums[i];
                    mp[nums[i]]--;
                    if (mp[nums[i]] == 0) {
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            mp[nums[j]]++;
            if (mp.size() == j - i + 1)
                ans = max(ans, sum);
            j++;
        }
        return ans;
    }
};