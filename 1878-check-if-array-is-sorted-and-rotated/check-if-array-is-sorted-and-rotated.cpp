class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        temp.reserve(2 * temp.size()); 
        temp.insert(temp.end(), temp.begin(), temp.end());
        for (int i = 0; i <n; i++) {
            bool flag=true;
            for(int j=i;j<i+n;j++){
                if(temp[j]!=nums[j-i]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};