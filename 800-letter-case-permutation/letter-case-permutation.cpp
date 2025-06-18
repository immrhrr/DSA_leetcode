class Solution {
public:
    void solve(string s, vector<string>& ans, int ind) { 
        int n = s.size(); 
        if(ind>=n){
            ans.push_back(s);
            return;
        }
        if(s[ind]>='0'&&s[ind]<='9'){
            solve(s,ans,ind+1);
        }
        else if(s[ind]>='a'&&s[ind]<='z'){
            solve(s,ans,ind+1);
            char ch=s[ind];
            ch=toupper(ch);
            s[ind]=ch;
            solve(s,ans,ind+1);
        }
        else{
            solve(s,ans,ind+1);
            char ch=s[ind];
            ch=tolower(ch);
            s[ind]=ch;
            solve(s,ans,ind+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, ans, 0);
        return ans;
    }
};