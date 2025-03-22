class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        string ans=s;
        while(i<j){
            char c1=s[i];
            char c2=s[j];
            ans[i]=min(c1,c2);
            ans[j]=ans[i];
            i++;j--;
        }
        return ans;
        
    }
};