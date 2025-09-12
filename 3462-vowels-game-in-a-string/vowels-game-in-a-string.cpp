class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.size();
        int vowel=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
                vowel++;
            }
        }
        if(vowel%2==1){
            return true;
        }
        else if(vowel==0)return false;


        
        return true;
    }
};