class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] != ']') {
                st.push(string(1, s[i]));
            } else {
                // collect the string inside [...]
                string temp;
                while (!st.empty() && st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }

                // pop the '['
                st.pop();

                // collect digits for repeat count
                string num;
                while (!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }

                int count = stoi(num);
                string expanded;
                for (int j = 0; j < count; j++) {
                    expanded += temp;
                }

                // push back the expanded string
                st.push(expanded);
            }
        }

        // combine everything left in the stack
        string ans;
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
