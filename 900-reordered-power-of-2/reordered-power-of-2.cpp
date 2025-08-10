class Solution {
public:
    unordered_set<string> st;
    void helper() {
        string s = "";
        for (int i = 0; i <= 30; i++) {
            s = to_string(1 << i);
            sort(s.begin(), s.end());
            st.insert(s);
        }

        return;
    }
    bool reorderedPowerOf2(int n) {
        if(st.empty())
        helper();
        string temp = to_string(n);
        sort(temp.begin(), temp.end());
        if (st.find(temp) != st.end())
            return true;
        return false;
    }
};