class Solution {
public:
    void make_lps(vector<int> &lps, string &s) {
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
    string longestPrefix(string s) {
        int n=s.size();
        if (n <= 1) return "";

        vector<int> lps(n, 0);
        make_lps(lps, s);
        int len=lps[n-1];
        string ans=s.substr(0,len);
        return ans;
        
    }
};