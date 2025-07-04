class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        if(k==1) return'a';
        long long len=1;
        long long newk=-1;
        int op=-1;
        int n=operations.size();
        for(int i=0;i<n;i++){
            len=len*2;
            if(len>=k){
                op=operations[i];
                newk=k-len/2;
                break;
            }
        }
       char ch= kthCharacter(newk,operations);
       if(op==0){
        return ch;
       }
       else if(op==1){
        return ch=='z'?'a':ch+1;
       }
       return 'a';
    }
};