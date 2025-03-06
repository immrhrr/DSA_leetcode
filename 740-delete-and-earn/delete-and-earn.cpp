class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=nums.size();
        vector<int>frq(1e4+1,0);
        for(int i=0;i<n;i++){
            frq[nums[i]]+=nums[i];
        }
        int prev1=frq[1];
        int prev2=0;
        int curr=prev1;
        for(int i=2;i<frq.size();i++){
        
           curr=max(prev1,prev2+frq[i]);
           prev2=prev1;
           prev1=curr;
        }
        return curr;
    }
};