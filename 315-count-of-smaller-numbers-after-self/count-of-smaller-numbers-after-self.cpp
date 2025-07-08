class Solution {
public:
    vector<int> ans;

    void merge(vector<pair<int, int>>& nums, int l, int mid, int r) {
        // --- 1) COUNT PASS (minimal addition) ---
        // Both halves nums[l..mid] and nums[mid+1..r] are sorted ascending from recursion
        int j = mid + 1;
        for (int i = l; i <= mid; ++i) {
            // advance j while right[j] < left[i]
            while (j <= r && nums[i].first > nums[j].first) {
                ++j;
            }
            // all elements from mid+1 .. (j-1) are smaller than nums[i]
            ans[nums[i].second] += (j - (mid + 1));
        }

        // --- 2) YOUR ORIGINAL MERGE (ascending order) ---
        vector<pair<int,int>> left(nums.begin()+l,      nums.begin()+mid+1);
        vector<pair<int,int>> right(nums.begin()+mid+1, nums.begin()+r+1);

        int i = 0, k = l;
        j = 0;
        int n1 = left.size(), n2 = right.size();

        while (i < n1 && j < n2) {
            if (left[i].first <= right[j].first) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }
        while (i < n1) nums[k++] = left[i++];
        while (j < n2) nums[k++] = right[j++];
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
        ans.assign(n, 0);
        vector<pair<int,int>> temp;
        temp.reserve(n);
        for (int i = 0; i < n; ++i)
            temp.emplace_back(nums[i], i);

        mergesort(temp, 0, n - 1);
        return ans;
    }
};
