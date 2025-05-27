class Solution {
public:
    string resultingString(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
             if(st.empty()){
                st.push(s[i]);
                continue;
            }
            char ch=s[i];
            int curr=ch-'0';
            int top=st.top()-'0';
            if(abs(top-curr)==1||abs(top-curr)==25){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
           
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};