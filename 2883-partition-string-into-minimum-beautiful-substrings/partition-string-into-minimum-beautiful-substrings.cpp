class Solution {
public:
    bool check(string&s,int start,int end){
        unordered_set<string>st;
        st.insert("11110100001001");
        st.insert("110000110101");
        st.insert("1");
        st.insert("101");
        st.insert("1001110001");
        st.insert("1111101");
        st.insert("11001");
        string temp=s.substr(start,end-start+1);
        if(st.find(temp)==st.end())return false;
        return true;
    }
    int solve(string&s,int ind){
        int n=s.size();
        if(ind>=n)return 0;
        int ans=100;
        int temp=0;
        for(int i=ind;i<n;i++){
            if(check(s,ind,i)){
                int temp=solve(s,i+1);
                if(temp!=100){
                    ans=min(ans,1+temp);
                }
            }
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        int ans=solve(s,0);
        if(ans>=100)return -1;
        return ans;
    }
};