class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int mini = INT_MAX, maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        int min_ind = -1, max_ind = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxi) max_ind = i;
            if (nums[i] == mini) min_ind = i;
        } 
        
        int left = min(min_ind, max_ind);
        int right = max(min_ind, max_ind);

        // 3 valid choices:
        int delete_both_from_front = right + 1;
        int delete_both_from_back  = n - left;
        int delete_from_both_sides = (left + 1) + (n - right);

        return min({delete_both_from_front, delete_both_from_back, delete_from_both_sides});
    }
};