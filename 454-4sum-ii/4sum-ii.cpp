class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                     vector<int>& nums4) {
        unordered_map<long long,int> mp;
        for (int k : nums3) {
            for (int l : nums4) {
                mp[k + l]++;
            }
        }
        int ans = 0;
        int n = nums1.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                long long temp = nums1[i] + nums2[j];
                if (mp.find(-temp) != mp.end()) {
                    ans += mp[-temp];
                }
            }
        }
        return ans;
    }
};