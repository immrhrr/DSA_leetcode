class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n - 1;
        while (j > i) {
            int sum = nums[i] + nums[j];
            if (sum == target) {
                return {i + 1, j + 1};
            } else if (sum > target) {
                j--;
            }
            else{
                i++;
            }
        }
        return{0,0};
    }
};