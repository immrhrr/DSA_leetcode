class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int leftSum=0;
        int rightSum=0;
        int leftQ=0;
        int rightQ=0;
        for(int i=0;i<n;i++){
            //left
            if(2*i<n){
                if(num[i]=='?'){
                    leftQ++;
                }
                else {
                    leftSum+=num[i]-'0';
                }
                
            }
            else{
                if(num[i]=='?'){
                    rightQ++;
                }
                else {
                    rightSum+=num[i]-'0';
                }
            }
        }
        return 2*leftSum+9*leftQ!=2*rightSum+9*rightQ;
    }
};