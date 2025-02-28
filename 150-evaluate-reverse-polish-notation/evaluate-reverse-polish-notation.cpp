class Solution {
public:
   int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        
        for (int i = 0; i < n; i++) { // Iterate from left to right
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int right = st.top(); st.pop(); // First pop is right operand
                int left = st.top(); st.pop();  // Second pop is left operand
                
                if (tokens[i] == "+") st.push(left + right);
                else if (tokens[i] == "-") st.push(left - right);
                else if (tokens[i] == "*") st.push(left * right);
                else st.push(left / right);
            } 
            else { // If it's a number, push to stack
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};