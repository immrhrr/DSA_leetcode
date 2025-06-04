class Solution {
public:
    bool check(string&word,int ind,int l,string ans){
        int n=word.size();
        int i=0;
        while(i<ans.size()){
            if(ans[i]==word[ind]){
                ind++;
                i++;
            }
            else{
                if(word[ind]-'a'>ans[i]-'a'){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if(ans.size()<l){
            return true;
        }
        return false;
    }
    string answerString(string word, int m) {
        int n=word.size();
        if(m==1)return word;
        string ans=string(1,word[0]);
        string temp="";
        for(int i=0;i<n;i++){
            for(int l=1;l<=n-m+1;l++){
                if(i+l>n)break;
                if(check(word,i,l,ans)){
                    ans=word.substr(i,n-m+1);
                    break;
                }
                else{
                    if(ans.back()!=word[i+l-1])break;
                }
            }
        }
        return ans;
    }
};