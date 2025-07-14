class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string temp = "";
        int startInd = -1;
        int endInd = n;
        for (int i = 0; i < n; i++) {
            if (s[i] != ' ') {
                startInd = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                endInd = i;
                break;
            }
        }
        if (startInd == -1)
            return "";
        string ans = "";
        for (int i = startInd; i <= endInd; i++) {
            if (s[i] != ' ') {
                temp += s[i];
            } else {
                if (temp.size() > 0) {
                    if (ans.size() == 0) {
                        ans = temp;
                    } else {
                        ans = temp + ' ' + ans;
                    }
                    temp = "";
                }
            }
        }

        if (temp.size() > 0) {
            if (ans.size() == 0) {
                ans = temp;
            } else {
                ans = temp + ' ' + ans;
            }
        }
        return ans;
    }
};