class Solution {
public:
    static bool comp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),comp);
        //max heap chahiye ek
        priority_queue<int>pq;
        int curr_time=0;
        for(int i=0;i<n;i++){
            int duration=courses[i][0];
            curr_time+=duration;
            pq.push(duration);
            int limit=courses[i][1];
            if(limit<curr_time){
                int top=pq.top();
                curr_time-=top;
                    pq.pop();
            }
        }
        return pq.size();
        
    }
};