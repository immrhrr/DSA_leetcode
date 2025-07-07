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
        for (int i = 1; i <= 1e5 + 1; i++) {
            st.insert(i);
        }
        int ans = 0;
        int n = events.size();
        for (int i = 0; i < n; i++) {
            int a = events[i][0];
            int b = events[i][1];
            // find the smallest number greater than or equal to a and smaller
            // than equal to b in the set st then erase that val from set and
            // ans++;
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