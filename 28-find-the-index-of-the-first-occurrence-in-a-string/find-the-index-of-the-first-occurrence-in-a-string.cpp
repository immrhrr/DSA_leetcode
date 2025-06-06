class Solution {
public:
     bool is_match(string txt,string pat,int ind){
        int n=pat.size();
        for(int i=0;i<n;i++){
            if(pat[i]!=txt[ind+i])return false;
        }
        return true;
    }
    int strStr(string txt, string pat) {
       int n=txt.size();
       int m=pat.size();
       int txt_hash=0;
       int pat_hash=0;
       int mod=1e3;
       int base=26;
       int power=1;
       
       for(int i=m-1;i>=0;i--){
           int pat_curr=pat[i]-'a'+1;
           int txt_curr=txt[i]-'a'+1;
           txt_hash=(txt_hash+(txt_curr*power)%mod)%mod;
           pat_hash=(pat_hash+(pat_curr*power)%mod)%mod;
           power=(power*base)%mod;
       }
       if(txt_hash==pat_hash&&is_match(txt,pat,0)){
           return 0;
       }
       int highest_power=1;
       for(int i=1;i<m;i++){
           highest_power=(highest_power*base)%mod;
       }
       
       for(int i=1;i<=n-m;i++){
           int left_val=txt[i-1]-'a'+1;
           txt_hash=(txt_hash-(left_val*highest_power)%mod+mod)%mod;
           txt_hash=(txt_hash*base)%mod;
           txt_hash=(txt_hash+(txt[i+m-1]-'a'+1))%mod;
           if(txt_hash==pat_hash&&is_match(txt,pat,i)){
              return i;
           }
       }
       return -1;
    }
};