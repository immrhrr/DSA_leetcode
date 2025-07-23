class Solution {
public:
    int solve_ba(string& s, int points, string& temp) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'a' && !st.empty() && st.top() == 'b') {
                st.pop();
                ans += points;
            } else {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return ans;
    }
    int solve_ab(string& s, int points, string& temp) {
        stack<char> st;
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == 'b' && !st.empty() && st.top() == 'a') {
                st.pop();
                ans += points;
            } else {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        if (x > y) {
            string str1 = "";
            string str2 = "";
            int temp = solve_ab(s, x, str1);
            temp += solve_ba(str1, y, str2);
            return temp;
        } else {
            string str1 = "";
            string str2 = "";
            int temp = solve_ba(s, y, str1);
            temp += solve_ab(str1, x, str2);
            return temp;
        }
    }
};