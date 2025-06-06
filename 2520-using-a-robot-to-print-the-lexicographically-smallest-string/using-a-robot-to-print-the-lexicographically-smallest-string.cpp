class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> temp(n);
        temp[n - 1] = s[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            temp[i] = min(temp[i + 1], s[i]);
        }

        string ans = "", t = "";
        int i = 0;
        while (i < n) {
            t += s[i];
            char min_char = (i + 1 < n) ? temp[i + 1] : '{';  // safe sentinel
            while (!t.empty() && t.back() <= min_char) {
                ans += t.back();
                t.pop_back();
            }
            i++;
        }

        reverse(t.begin(), t.end());
        ans += t;
        return ans;
    }
};
