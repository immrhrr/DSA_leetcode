class Solution {
public:
    void solve(queue<string>& q, string curr, unordered_set<string> &st) {
        st.insert(curr);
        for (int i = 0; i < 4; i++) {
            char ch = curr[i];
            char in = (ch == '9') ? '0': ch + 1;
            char dec = (ch == '0') ? '9':ch - 1;
            curr[i] = dec;
            if (st.find(curr) == st.end()) {
                q.push(curr);
                st.insert(curr);
            }
            curr[i] = in;
            if (st.find(curr) == st.end()) {
                q.push(curr);
                st.insert(curr);
            }
            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> st(deadends.begin(), deadends.end());
        string start = "0000";
        if (st.find(start) != st.end())
            return -1;
        queue<string> q;
        q.push(start);
        int level = 0;
        while (!q.empty()) {
            int m = q.size();
            while (m--) {
                string curr = q.front();
                if (curr == target)
                    return level;
                q.pop();
                solve(q, curr, st);
            }
            level++;
        }
        return -1;
    }
};