class Solution {
public:
    unordered_set<string> st;
    vector<string> ans;

    static bool comp(const string &s1, const string &s2) {
        return s1.size() < s2.size();
    }

    bool check(const string &word, int ind,vector<int>&dp) {
        int n = word.size();
        if (ind == n) return dp[ind]= true;
        if(dp[ind]!=-1)return dp[ind];

        for (int i = ind; i < n; ++i) {
            string prefix = word.substr(ind, i - ind + 1);
            if (st.find(prefix) != st.end()) {
                if (check(word, i + 1,dp)) return dp[ind]=true;
            }
        }
        return dp[ind]= false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string> &words) {
        sort(words.begin(), words.end(), comp);

        for (string &word : words) {
            if (word.empty()) continue;
            vector<int>dp(word.size()+1,-1);
            if (check(word, 0,dp)) {
                ans.push_back(word);
            }
            // Insert only after checking so word doesn’t use itself
            st.insert(word);
        }

        return ans;
    }
};
