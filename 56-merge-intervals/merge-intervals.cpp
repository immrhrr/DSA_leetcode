class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n=intervals.size();
        for(int i=1;i<n;i++){
            int curr_start=intervals[i][0];
            int prev_end=ans.back()[1];
            if(curr_start<=prev_end){
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};