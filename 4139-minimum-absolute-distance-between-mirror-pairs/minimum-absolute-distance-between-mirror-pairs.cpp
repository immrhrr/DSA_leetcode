class Solution {
public:
    int find(int x) {
        string given = to_string(x);
        reverse(given.begin(), given.end());
        return stoi(given);
    }
    
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        
        // This map stores { reverse(nums[i]) : latest_index_i }
        unordered_map<int, int> expected_vals;

        for (int j = 0; j < n; j++) {
            // Check if the current number nums[j] is exactly the reverse 
            // of some earlier number nums[i]
            if (expected_vals.find(nums[j]) != expected_vals.end()) {
                ans = min(ans, j - expected_vals[nums[j]]);
            }
            
            // Calculate what a future nums[j] needs to be to pair with this nums[i]
            int rev = find(nums[j]);
            
            // Store or update the index. Keeping the latest index ensures 
            // we get the minimum distance 'j - i' for future matches.
            expected_vals[rev] = j;
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};