class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = INT_MIN;
        unordered_map<int, int> mp;
        int sum = 0;
        int cnt = 0;
        while (j < n) {
            if (nums[j]>0&&mp.find(nums[j])==mp.end()) {
                cnt++;
                mp[nums[j]]++;
                sum += nums[j];
                while (i < j && mp.size() != cnt) {
                    if (nums[i] <= 0) {
                        i++;
                    } else {
                        mp[nums[i]]--;
                        if (mp[nums[i]] == 0) {
                            mp.erase(nums[i]);
                        }
                        sum -= nums[i];
                        i++;
                        cnt--;
                    }
                }
                ans = max(ans, sum);
            }
             j++;
        }
        if(ans==INT_MIN){
            //all are neg
            return *max_element(nums.begin(),nums.end());
        }
        return ans;
    }
};