class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        if(m>n){
            return s;
        }
      //  reverse(part.begin(),part.end());
        stack<char>st;
        for(int i=0;i<n;i++){
            st.push(s[i]);
            if(st.size()>=m&&st.top()==part[m-1]){
                string temp;
                for(int j=m-1;j>=0;j--){
                    if(!st.empty()&&st.top()==part[j]){
                         temp+=st.top();
                         st.pop();
                    }
                    else{
                        break;
                    }
                }
                reverse(temp.begin(),temp.end());
                if(temp!=part){
                    int x=temp.size();
                    for(int k=0;k<x;k++){
                        st.push(temp[k]);
                    }
                }
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