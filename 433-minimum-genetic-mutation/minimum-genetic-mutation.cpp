class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(end)) return -1;

        queue<string> q;
        q.push(start);
        int level = 0;
        unordered_set<string> visited;
        visited.insert(start);
        vector<char> genes = {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                q.pop();
                if (curr == end) return level;

                for (int i = 0; i < curr.size(); ++i) {
                    char original = curr[i];
                    for (char c : genes) {
                        curr[i] = c;
                        if (st.count(curr) && !visited.count(curr)) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[i] = original; // revert back
                }
            }
            level++;
        }

        return -1;
    }
};
