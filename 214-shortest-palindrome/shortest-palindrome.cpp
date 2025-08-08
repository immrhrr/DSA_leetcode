class Solution {
public:
    void find_lps(vector<int>&lps,string&t){
        int n=t.size();
        int pref=0;
        int suff=1;
        while(suff<n){
            if(t[pref]==t[suff]){
                lps[suff]=1+pref;
                pref++;
                suff++;
            }
            else{
                if(pref==0){
                    suff++;
                }
                else{
                    pref=lps[pref-1];
                }
            }
        }
        return;
    }
    string shortestPalindrome(string s) {
        string t=s;
        t+='#';
        string temp=s;
        reverse(temp.begin(),temp.end());
        t+=temp;
        int n=t.size();
        vector<int>lps(n,0);
        find_lps(lps,t);
        int len=s.size()-lps[n-1];
        
        string ans=temp.substr(0,len);
        ans+=s;
        return ans;

        
    }
};