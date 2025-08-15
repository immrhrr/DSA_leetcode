class Solution {
public:
    bool isSubsequence(string s, string t) {
        //if s is a subsequence of t
        int n=s.size();
        int m=t.size();
        if(n>m)return false;
        if(n==m)return s==t;
        int i=0;
        int j=0;
        while(i<n&&j<m){
            if(s[i]==t[j]){
                i++;j++;
            }
            else{
                j++;
            }
        }
        return i==n;
        
    }
};