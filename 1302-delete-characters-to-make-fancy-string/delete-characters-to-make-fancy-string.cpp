class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        string ans="";
        int ind=0;
        for(int i=0;i<n;i++){
            if(i<2||ans[ind-1]!=s[i]||ans[ind-2]!=s[i]){
                ans+=s[i];
                ind++;
            }
        }
        return ans;
    }
};