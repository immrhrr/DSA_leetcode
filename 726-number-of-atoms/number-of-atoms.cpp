class Solution {
public:
    map<string, int> dfs(string str, int& i) {
        int n = str.size();
        map<string, int> mp;

        while (i < n) {
            if (str[i] == '(') {
                i++;
                auto t = dfs(str, i);
                int left = i;
                while (i < n && isdigit(str[i])) {
                    i++;
                }
                int cnt = 1;
                if (i > left) {
                    cnt = stoi(str.substr(left, i - left));
                }
                for (auto& [k, v] : t) {
                    mp[k] += v * cnt;
                }
            } else if (str[i] == ')') {
                i++;
                break;
            } else {
                int left = i;
                i++;
                while (i < n && str[i] >= 'a' && str[i] <= 'z') {
                    i++;
                }
                string key = str.substr(left, i - left);
                left = i;
                while (i < n && isdigit(str[i])) {
                    i++;
                }
                int cnt = 1;
                if (i > left) {
                    cnt = stoi(str.substr(left, i - left));
                }
                mp[key] += cnt;
            }
        }

        return mp;
    }
    string countOfAtoms(string formula) {
        int i = 0;
        auto mp = dfs(formula, i);
        stringstream ss;

        for (auto& [k, v] : mp) {
            ss << k;
            if (v > 1) ss << v;
        }
        return ss.str();
    }
};