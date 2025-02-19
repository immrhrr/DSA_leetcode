class Solution {
public:
    string getHappyString(int n, int k) {
        // Total number of happy strings of length n is 3 * 2^(n - 1)
        int totalStrings = 3 * (1 << (n - 1));
        if (k > totalStrings) {
            return "";  // Return an empty string if k is out of range
        }

        string ans = "";
        // Determine the first character ('a', 'b', or 'c')
        if (k <= totalStrings / 3) {
            ans += 'a';
        } else if (k <= 2 * totalStrings / 3) {
            ans += 'b';
            k -= totalStrings / 3;
        } else {
            ans += 'c';
            k -= 2 * totalStrings / 3;
        }
        totalStrings/=3;

        // Build the rest of the string
        for (int i = 1; i < n; i++) {
            totalStrings /= 2;  // Half the remaining possibilities at each step
            if (k <= totalStrings) {
                // Choose the smallest valid character that is not equal to the last character
                if (ans.back() == 'a') {
                    ans += 'b';
                } else {
                    ans += 'a';
                }
            } else {
                // Choose the next valid character that is not equal to the last character
                k -= totalStrings;  // Move to the next half of the sequence
                if (ans.back() == 'a') {
                    ans += 'c';
                } else if (ans.back() == 'b') {
                    ans += 'c';
                } else {
                    ans += 'b';
                }
            }
        }

        return ans;
    }
};
