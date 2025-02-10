class Solution {
public:
    string clearDigits(string s) {
        int write = 0;  // Pointer to overwrite the valid character
        for (char c : s) {
            if (isdigit(c)) {
                if (write > 0) write--;  // Remove last valid character
            } else {
                s[write++] = c;  // Overwrite s with valid chars
            }
        }
        return s.substr(0, write);  // Return only the valid portion
    }
};
