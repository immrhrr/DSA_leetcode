class Solution {
public:
    long long numOfSubsequences(string s) {
        int n=s.size();
        if(n<2)return 0;
        string ss="";
        long long rt=0;
        long long rc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='L'||s[i]=='C'||s[i]=='T'){
                ss+=s[i];
            }
            if(s[i]=='T'){
                rt++;
            }
            if(s[i]=='C'){
                rc++;
            }
        }
        long long rt1=rt;
        long long rt2=rt;
        long long ll=0;
        n=ss.size();
        long long normal=0;
        long long extra=0;
        for(int i=0;i<n;i++){
            if(ss[i]=='L'){
                ll++;
            }
            if(ss[i]=='T'){
                rt--;
            }
            if(ss[i]=='C'){
                normal=normal+(ll*rt);
            }
        }
        //try for extra possibility by inserting one
        //case1:L
        long long temp1=0;
        for(int i=0;i<n;i++){
            if(ss[i]=='T'){
                rt2--;
            }
            if(ss[i]=='C'){
                temp1+=rt2;
            }
        }
        //case2:C
        long long temp2=0;
        ll=0;
        for(int i=0;i<n;i++){
            if(ss[i]=='L'){
                ll++;
            }
            if(ss[i]=='T'){
                rt1--;
            }
            temp2=max(temp2,ll*rt1);
        }
        //case3:T
        ll=0;
        long long temp3=0;
        for(int i=0;i<n;i++){
            if(ss[i]=='L'){
                ll++;
            }
            if(ss[i]=='C'){
                temp3+=ll;
            }
        }
        extra=max({temp1,temp2,temp3});
        return normal+extra;
    }
};