class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(maxi==2&&s[i]=='a'){
                return false;
            }
            if(s[i]=='a'){
                maxi=max(maxi,1);
            }
            if(s[i]=='b'){
                maxi=max(maxi,2);
            }
        }
        return true;
    }
};