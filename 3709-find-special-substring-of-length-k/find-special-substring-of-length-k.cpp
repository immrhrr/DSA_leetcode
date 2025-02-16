class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n=s.size();
        if(n<k){
            return false;
        }
        for(int i=0;i<=n-k;i++){
            bool flag=true;
            for(int j=i;j<=i+k-1;j++){
                if(s[i]!=s[j]){
                    flag=false;
                    break;
                }
            }
            int l=i-1;
            int r=i+k;
            if(flag==true&&l>=0&&s[i]==s[l]){
                flag=false;
            }
            if(flag&&r<n&&s[i]==s[r]){
                flag=false;
            }
            if(flag){
                return true;
            }
        }
        return false;
    }
};