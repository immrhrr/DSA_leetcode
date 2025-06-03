class Solution {
public:
    int at_most(vector<int>&nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        // at most k distinct chars
        // keep findina all sub string with at most k distinct chars ending at
        // index j
        while (j < n) {
            mp[nums[j]]++;
            while (mp.size() > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return at_most(nums, k) - at_most(nums, k - 1);
    }
};