class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int last=-1;
        for(int i=n-1;i>=0;i--){
            if((num[i]-'0')%2==1){
                last=i;
                break;
            }
        }
        if(last==-1)return "";
        return num.substr(0,last+1);
        
    }
};