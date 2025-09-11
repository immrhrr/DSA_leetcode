class Solution {
public:
    string sortVowels(string s) {
        vector<int>cap(26,0);
        vector<int>small(26,0);
        int n=s.size();
        unordered_set<char>s1={'A','E','I','O','U'};
        unordered_set<char>s2={'a','e','i','o','u'};
        string ans="";
        for(int i=0;i<n;i++){
            ans+='#';
        }
        for(int i=0;i<n;i++){
            if(s1.find(s[i])==s1.end()&&s2.find(s[i])==s2.end()){
                ans[i]=s[i];
            }
            else if(s1.find(s[i])==s1.end()){
                small[s[i]-'a']++;

            }
            else if(s2.find(s[i])==s2.end()){
                cap[s[i]-'A']++;

            }
        }
        string temp="";
        for(int i=0;i<26;i++){
            int m=cap[i];
            for(int j=0;j<m;j++){
                temp+=('A'+i);
            }
        }
        for(int i=0;i<26;i++){
            int m=small[i];
            for(int j=0;j<m;j++){
                temp+=('a'+i);
            }
        }
        int ind=0;
        for(int i=0;i<n;i++){
            if(ans[i]=='#'){
                ans[i]=temp[ind];
                ind++;
            }
        }
        return ans;
        
    }
};