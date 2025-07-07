class Solution {
public:
    vector<int> ans;

    void merge(vector<pair<int, int>>& nums, int l, int mid, int r) {
        vector<pair<int, int>> left(nums.begin() + l, nums.begin() + mid + 1);
        vector<pair<int, int>> right(nums.begin() + mid + 1, nums.begin() + r + 1);

        int n1 = left.size();
        int n2 = right.size();
        int i = 0, j = 0;
        int ind = l;
        int countRight = 0;

        while (i < n1 && j < n2) {
            if (left[i].first <= right[j].first) {
                // All previous right[j]s are smaller than left[i]
                ans[left[i].second] += countRight;
                nums[ind++] = left[i++];
            } else {
                // right[j] < left[i]
                countRight++;
                nums[ind++] = right[j++];
            }
        }

        while (i < n1) {
            ans[left[i].second] += countRight;
            nums[ind++] = left[i++];
        }
        while (j < n2) {
            nums[ind++] = right[j++];
        }
    }

    void mergesort(vector<pair<int, int>>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n, 0);
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({nums[i], i});
        }
        mergesort(temp, 0, n - 1);
        return ans;
    }
};
