class Solution {
public:
    void find_lps(vector<int>&lps,string&needle){
        int n=needle.size();
        int pref=0;
        int suff=1;
        while(suff<n){
            if(needle[pref]==needle[suff]){
                lps[suff]=1+pref;
                pref++;suff++;
            }
            else{
                if(pref==0){
                    lps[suff]=0;
                    suff++;
                }
                else{
                    pref=lps[pref-1];
                }
            }
        }
        return;
    }
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        vector<int>lps(m,0);
        find_lps(lps,needle);
        int first=0;
        int second=0;
        while(first<n&&second<m){
            if(haystack[first]==needle[second]){
                first++;
                second++;
            }
            else{
                if(second==0){
                    first++;
                }
                else{
                    second=lps[second-1];
                }
            }
        }
        if(second==m){
            return first-second;
        }
        return -1;
        
    }
};