class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        
        int prev_start=meetings[0][0];
        int prev_end=meetings[0][1];
        int cnt=0;
        for(int i=1;i<n;i++){
            int curr_start=meetings[i][0];
            int curr_end=meetings[i][1];
            if(curr_start<=prev_end){
                prev_end=max(prev_end,curr_end);
            }
            else{
              
                cnt+=(prev_end-prev_start+1);
                prev_start=curr_start;
                prev_end=curr_end;
            }
        }
      
         cnt+=(prev_end-prev_start+1);
        return days-cnt;
    }
};