class Solution {
public:
    int solve(string& digits, int ind, vector<int>& dp) {
        int n = digits.size();
        
        //got one valid message
        if (ind >= n) {
            return 1;
        }
        //if the current digit is zero then it will not give answer
        if (digits[ind] == '0')
            return 0;
        //using memoization
        if (dp[ind] != -1)
            return dp[ind];

        int onestep = 0;
        int twostep = 0;
       
        onestep = solve(digits, ind + 1, dp);
        // check for valid two digit
        if (ind + 1 < n) {
            int d1 = digits[ind] - '0';
            int d2 = digits[ind + 1] - '0';
            if (d1 == 1 || (d1 == 2 && d2 <= 6))
                twostep = solve(digits, ind + 2, dp);
        }
        return dp[ind] = onestep + twostep;
    }
    int numDecodings(string digits) {
        int n = digits.size();
        vector<int> dp(n + 1, -1);
        return solve(digits, 0, dp);
    }
};