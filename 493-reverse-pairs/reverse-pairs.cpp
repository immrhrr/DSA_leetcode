class Solution {
public:
    int ans = 0;

    void merge(vector<int>& nums, int l, int mid, int r) {
        // ── 1) COUNT PASS (before merging) ──
        int j = mid + 1;
        for (int i = l; i <= mid; ++i) {
            // Cast to long long to avoid overflow
            while (j <= r && (long long)nums[i] > 2LL * nums[j]) 
                ++j;
            ans += (j - (mid + 1));
        }

        // ── 2) STANDARD ASCENDING MERGE ──
        vector<int> left, right;
        for (int i = l; i <= mid;       ++i) left.push_back(nums[i]);
        for (int i = mid + 1; i <= r;   ++i) right.push_back(nums[i]);

        int i = 0, k = l;
        j = 0;
        int n1 = left.size(), n2 = right.size();

        // merge in ascending order
        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }
        while (i < n1) nums[k++] = left[i++];
        while (j < n2) nums[k++] = right[j++];
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, r);
        merge(nums, l, mid, r);
    }

    int reversePairs(vector<int>& nums) {
        mergesort(nums, 0, (int)nums.size() - 1);
        return ans;
    }
};
