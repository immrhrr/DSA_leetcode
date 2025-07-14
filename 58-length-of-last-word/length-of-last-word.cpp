class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.size();
        int ind=n-1;
        while(s[ind]==' '){
            ind--;
        }
        if(ind<0)return 0;
        int len=0;
        for(int i=ind;i>=0;i--){
            if(s[i]!=' '){
                len++;
            }
            else{
                return len;
            }

        }
        return len;
        
    }
};