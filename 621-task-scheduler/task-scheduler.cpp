class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26, 0);
        for (char ch : tasks) {
            mp[ch - 'A']++;
        }
        priority_queue<int> pq;
        for (int i = 0; i< 26; i++) {
            if (mp[i] > 0) {
                pq.push(mp[i]);
            }
        }
        int ans = 0;
        while (!pq.empty()) {
            vector<int> temp;
            for (int i = 1; i <= n + 1; i++) {
                if (!pq.empty()) {
                    int x = pq.top();
                    x--;
                    pq.pop();
                    temp.push_back(x);
                }
            }
            for (int x : temp) {
                if (x > 0) {
                    pq.push(x);
                }
            }
            if (pq.empty()) {
                ans += temp.size();
            } else {
                ans += n + 1;
            }
        }
        return ans;
    }
};