class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> mp;
        for (int i = 0; i < m; i++) {
            mp[t[i]]++;
        }
        string ans = "";
        int curr_size=INT_MAX;
        int start=-1;
        int req = m;
        int i = 0;
        int j = 0;
        while (j < n) {
            if (mp[s[j]] > 0) {
                req--;
            }
            mp[s[j]]--;
            while (req == 0) {
                if (j - i + 1 < curr_size) {
                    start=i;
                    curr_size=j-i+1;
                }
                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    req++;
                }
                i++;
            }
            j++;
        }
        if(start==-1)return ans;
        ans=s.substr(start,curr_size);
        return ans;
    }
};