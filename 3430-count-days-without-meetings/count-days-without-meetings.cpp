class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<pair<int,int>>temp;
        int prev_start=meetings[0][0];
        int prev_end=meetings[0][1];
        for(int i=1;i<n;i++){
            int curr_start=meetings[i][0];
            int curr_end=meetings[i][1];
            if(curr_start<=prev_end){
                prev_end=max(prev_end,curr_end);
            }
            else{
                temp.push_back({prev_start,prev_end});
                prev_start=curr_start;
                prev_end=curr_end;
            }
        }
        temp.push_back({prev_start,prev_end});
        int cnt=0;
        for(int i=0;i<temp.size();i++){
            cnt+=(temp[i].second-temp[i].first+1);

        }
        return days-cnt;
    }
};