class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long temp = 0;
        unordered_map<int, int> mp;
        for (int i = n - 1; i >= 0; i--) {
            if (mp.find(nums[i] - i) != mp.end()) {
                temp += ((n - 1 - i) - mp[nums[i] - i]);
            } else {
                temp += (n - 1 - i);
            }
            mp[nums[i] - i]++;
        }
        return temp;
    }
};