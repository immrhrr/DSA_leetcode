class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1);
        vector<int> temp(n, 1);
        // length of lis ending at ith index
        int ans = 0;
        for (int curr = 0; curr < n; curr++) {
            for (int prev = 0; prev < curr; prev++) {
                if (nums[curr] > nums[prev]) {
                    if (lis[curr] == 1+lis[prev]) {
                        temp[curr] += temp[prev];
                    } else if (lis[curr]<1+lis[prev]) {
                        lis[curr]=1+lis[prev];
                        temp[curr] = temp[prev];
                    }
                }
            }
            ans=max(ans,lis[curr]);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (lis[i] == ans) {
                cnt += temp[i];
            }
        }
        return cnt;
    }
};