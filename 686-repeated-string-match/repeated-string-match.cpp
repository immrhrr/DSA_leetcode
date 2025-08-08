class Solution {
public:
    void make_lps(vector<int>&lps,string&s){
        int n=s.size();
        int pref=0;
        int suff=1;
        while(suff<n){
            if(s[pref]==s[suff]){
                lps[suff]=1+pref;
                pref++;
                suff++;
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
    bool check(string&a,string&b,vector<int>&lps){
        //a mein hum b ko dekh rhe hain bro
        int n=a.size();
        int m=b.size();
        int first=0;
        int second=0;
        while(first<n&&second<m){
            if(a[first]==b[second]){
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
        return second==m;

    }
    int repeatedStringMatch(string a, string b) {
        int n=a.size();
        int m=b.size();
        int temp=(m+n-1)/n;
        vector<int>lps(m,0);
        make_lps(lps,b);
        string s=a;
        for(int i=1;i<temp;i++){
            s+=a;
        }
        if(check(s,b,lps)){
            return temp;
        }
        s+=a;
        if(check(s,b,lps)){
            return temp+1;
        }
        return -1;
    }
};