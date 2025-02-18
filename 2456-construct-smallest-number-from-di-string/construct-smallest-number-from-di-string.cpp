class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        bool flag = false;
        string temp = "";

        // Build the initial string of numbers from '1' to 'n+1'
        for (int i = 1; i <= n + 1; i++) {
            temp += i + '0';
        }

        while (!flag) {
            bool check = true;
            for (int i = 0; i < n; i++) {
                if (pattern[i] == 'I' && temp[i + 1] <= temp[i]) {
                    check = false;
                    break;
                }
                if (pattern[i] == 'D' && temp[i + 1] >= temp[i]) {
                    check = false;
                    break;
                }
            }

            if (check) {
                flag = true;
            } else {
                next_permutation(begin(temp), end(temp));  // No assignment here
            }
        }

        return temp;
    }
};
