class Solution {
public:
    char kthCharacter(int k) {
        if(k==1)return 'a';
        string s="a";
        while(s.size()<k){
            string temp=s;
            for(int i=0;i<s.size();i++){
                char ch=s[i];
              temp+= ch=='z'? 'a':ch+1;
            }
            s=temp;
        }
        return s[k-1];
    }
};