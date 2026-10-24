class Solution {
public:
    int find_date(string s) {
        return (s[3] - '0') * 10 + (s[4] - '0');
    }

    int find_month(string s) {
        return (s[0] - '0') * 10 + (s[1] - '0');
    }

    int countDaysTogether(string aa, string la, string ab, string lb) {
        unordered_map<int, int> mp;

        mp[1] = 31;
        mp[2] = 28;
        mp[3] = 31;
        mp[4] = 30;
        mp[5] = 31;
        mp[6] = 30;
        mp[7] = 31;
        mp[8] = 31;
        mp[9] = 30;
        mp[10] = 31;
        mp[11] = 30;
        mp[12] = 31;

        int alice_start_date = find_date(aa);
        int alice_start_month = find_month(aa);
        int bob_start_date = find_date(ab);
        int bob_start_month = find_month(ab);

        int alice_end_date = find_date(la);
        int alice_end_month = find_month(la);
        int bob_end_date = find_date(lb);
        int bob_end_month = find_month(lb);

        int common = 0;

        int c_month_start = max(bob_start_month, alice_start_month);
        int c_month_end = min(bob_end_month, alice_end_month);

        for (int m = c_month_start; m <= c_month_end; m++) {

            int start = 1;
            int end = mp[m];

            if (m == alice_start_month)
                start = max(start, alice_start_date);

            if (m == bob_start_month)
                start = max(start, bob_start_date);

            if (m == alice_end_month)
                end = min(end, alice_end_date);

            if (m == bob_end_month)
                end = min(end, bob_end_date);

            for (int d = start; d <= end; d++) {
                common++;
            }
        }

        return common;
    }
};