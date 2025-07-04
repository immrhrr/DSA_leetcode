class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1)return 0;
        if(k==2)return 1;
        if(n==1){
            return 0;
        }
        bool is_k_odd=false;
        if(k%2==1){
            is_k_odd=true;
        }
        int temp=kthGrammar(n-1,(k+1)/2);
        if(is_k_odd){
            return temp;
        }
        return temp==0?1:0;
    }
};