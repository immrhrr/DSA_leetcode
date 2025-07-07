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
            int a = events[i][0];
            int b = events[i][1];
            auto it1 = st.lower_bound(a);
            if (it1 != st.end()) {
               if(*it1<=b){
                ans++;
                st.erase(*it1);
               }
            }
        }
        return ans;
    }
};