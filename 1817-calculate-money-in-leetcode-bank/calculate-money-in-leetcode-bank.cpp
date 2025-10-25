class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int mon=1;
        int curr=1;
        for(int i=1;i<=n;i++){
            if(i%7==1){
                ans+=mon;
                mon++;
                curr=mon;
            }
            else{
                ans+=curr;
                curr++;
            }
        }
        return ans;
    }
};
//(1 2 3 4 5 6 7)->28
//(2 3 4 5 6 7 8)->35
//(3 4 5 6 7 8 9)->42