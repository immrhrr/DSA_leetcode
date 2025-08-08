class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        //mini = 0; // Will be set on first push
    }

    void push(int val) {
        if (st.empty()) {
            st.push(val);
            mini = val;
        } else if (val >= mini) {
            st.push(val);
        } else {
            st.push(2LL * val - mini); // store modified value
            mini = val;
        }
    }

    void pop() {
        if (st.empty()) return;
        if (st.top() >= mini) {
            st.pop();
        } else {
            mini = 2LL * mini - st.top(); // restore previous min
            st.pop();
        }
    }

    int top() {
        if (st.empty()) return -1;
        if (st.top() >= mini) {
            return st.top();
        } else {
            return mini; // encoded value case
        }
    }

    int getMin() {
        return mini;
    }
};
