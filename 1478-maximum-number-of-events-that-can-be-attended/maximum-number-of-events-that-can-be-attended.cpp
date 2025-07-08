class Solution {
public:
    bool static comp(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) {
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), comp);
       //jo pehle khatm ho rha pehle usko try kro
       //agar dono same time pe khatm ho rha toh jo pehle aaya usko pehle
       //sort(events.begin(),events.end());
        set<int> st;
        int n = events.size();
        int mini=1e5+1;
        int maxi=0;
        for(int i=0;i<n;i++){
            mini=min(events[i][0],mini);
            maxi=max(events[i][1],maxi);
        }
        for (int i = mini; i <= maxi; i++) {
            st.insert(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int start = events[i][0];
            int end = events[i][1];
            auto it = st.lower_bound(start);
            if (it != st.end()) {
               if(*it<=end){
                ans++;
                st.erase(*it);
               }
            }
        }
        return ans;
    }
};