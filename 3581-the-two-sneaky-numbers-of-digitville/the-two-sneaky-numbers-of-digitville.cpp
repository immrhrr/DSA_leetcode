class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>frq(n,0);
        for(int i=0;i<n;i++){
            int curr=nums[i];
            frq[curr]++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(frq[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};