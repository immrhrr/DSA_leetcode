class Solution {
public:
    bool check(const vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }
    
    int minimumPairRemoval(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        if (check(nums)) {
            return 0;
        }
        int cnt = 0;
        while (!check(nums)) {
            int mini = INT_MAX; 
            int index = 0;
            
            for (int i = 0; i < nums.size() - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < mini) {
                    mini = sum;
                    index = i;
                }
            }
            
            vector<int> temp;
            for (int i = 0; i < index; i++) {
                temp.push_back(nums[i]);
            }
            temp.push_back(mini);
            for (int i = index + 2; i < nums.size(); i++) {
                temp.push_back(nums[i]);
            }
            
            nums = temp;
            cnt++;
        }
        return cnt;
    }
};
