class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int length=0;
         vector<int>pref(n,0);
        if(s[0]=='0'){
           pref[0]=1;
        }
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1];
            if(s[i]=='0'){
                pref[i]+=1;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                length++;
            }
            else{
                if(pow(2,length)<=k){
                    k=k-pow(2,length);
                    length++;
                }
            }
        }
        return length;
        
    }
};