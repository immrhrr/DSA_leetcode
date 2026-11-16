
class Solution {
public:
    string helper(string s, int start, int k) {
        int n = s.size();

        if (start + k > n)
            k = n - start;

        int temp = 0;

        for (int i = start; i < start + k; i++) {
            temp += s[i] - '0';
        }

        return to_string(temp);
    }

    string digitSum(string s, int k) {
        while (s.size() > k) {
            string str = "";

            for (int i = 0; i < s.size(); i += k) {
                str += helper(s, i, k);
            }

            s = str;
        }

        return s;
    }
};
