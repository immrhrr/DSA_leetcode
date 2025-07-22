class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five = 0;
        int ten = 0;
        int twenty = 0;
        for (int i = 0; i < n; i++) {
            if (bills[i] == 5) {
                five++;
                continue;
            } else if (bills[i] == 10) {
                ten++;
                if (five > 0) {
                    five--;
                } else {
                    return false;
                }
            } else {
                twenty++;
                // need 15
                if (five < 1) {
                    return false;
                }
                // 10,5
                if (ten > 0) {
                    ten--;
                    five--;
                    continue;
                }
                // 5,5,5
                else {
                    if (five < 3) {
                        return false;
                    } else {
                        five -= 3;
                    }
                }
            }
        }
        return true;
    }
};