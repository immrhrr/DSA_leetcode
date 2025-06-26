class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        int length=0;
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