class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int pro=1;
        int temp=n;
        while(temp>0){
            int digit=temp%10;
            sum+=digit;
            pro=pro*digit;
            temp=temp/10;
        }
        int temp2=sum+pro;
        return (n%temp2==0);
       
    }
};