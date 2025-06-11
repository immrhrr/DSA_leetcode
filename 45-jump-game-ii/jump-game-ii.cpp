class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int steps=0;
        int window_end=0;
        int farthest=0;
        for(int i=0;i<n;i++){
            if(window_end>=n-1)return steps;
            farthest=max(farthest,i+nums[i]);
            if(i==window_end){
                window_end=farthest;
                steps++;
            }
        }
        return steps;
    }
};