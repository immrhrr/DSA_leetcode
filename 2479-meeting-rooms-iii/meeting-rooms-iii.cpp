class Solution {
public:
    // pair<int,int>
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> finish_time(n, 0);
        int m = meetings.size();
        vector<int> cnt(n, 0);
        for (int i = 0; i < m; i++) {
            int end = meetings[i][1];
            int start = meetings[i][0];
            int duration = end - start;
            // find the first room with less than equal to end
            bool found = false;
             // no delay
            for (int j = 0; j < n; j++) {
                if (finish_time[j] <= start) {
                    finish_time[j] = end;
                    cnt[j]++;
                    found = true;
                    break;
                }
            }
            // delay
            if (!found) {
                int ind=-1;
                long long small=LLONG_MAX;
                for (int j = 0; j < n; j++) {
                   if(finish_time[j]<small){
                    small=finish_time[j];
                    ind=j;
                   }
                }
                finish_time[ind]+=duration;
                cnt[ind]++;
            }
        }
        int temp = 0;
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (cnt[i] > temp) {
                index = i;
                temp = cnt[i];
            }
        }
        return index;
    }
};