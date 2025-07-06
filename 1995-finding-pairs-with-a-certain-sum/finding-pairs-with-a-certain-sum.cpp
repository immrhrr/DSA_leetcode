class FindSumPairs {
public:
    vector<int> arr1;
    vector<int> arr2;
    unordered_map<int, int> mp;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        int n2 = arr2.size();
        for (int j = 0; j < n2; j++) {
            mp[arr2[j]]++;
        }
    }

    void add(int index, int val) {
        mp[arr2[index]]--;
        mp[arr2[index] + val]++;
        arr2[index]+=val;
    }

    int count(int tot) {
        int need = 0;
        int ans = 0;
        for (int i = 0; i < arr1.size(); i++) {
            need = tot - arr1[i];
            if(mp.find(need)!=mp.end())
            ans += mp[need];
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */