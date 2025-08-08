class Solution {
public:
    void find_lps(vector<int>& lps, string& s) {
        int n = s.size();
        int pref = 0, suff = 1;
        while (suff < n) {
            if (s[pref] == s[suff]) {
                lps[suff] = pref + 1;
                pref++;
                suff++;
            } else {
                if (pref == 0) {
                    lps[suff] = 0;
                    suff++;
                } else {
                    pref = lps[pref - 1];
                }
            }
        }
    }

    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        find_lps(lps, s);
        
        int len = lps[n - 1];
        return (len > 0 && n % (n - len) == 0);
    }
};
