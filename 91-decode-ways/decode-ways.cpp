class Solution {
public:
     int solve(string&digits,int ind,vector<int>&dp){
        int n=digits.size();
        if(digits[ind]=='0')return 0;
        if(ind>=n){
            return 1;
        }
        if(dp[ind]!=-1)return dp[ind];
        int onestep=0;
        int twostep=0;
        //if the current digit is zero then we have two make it twostep
        //if the current digit is non zero then only we can take one step
        if(digits[ind]!='0')
        onestep=solve(digits,ind+1,dp);
        //check for valid two digit
        if(ind+1<n){
            int d1=digits[ind]-'0';
            int d2=digits[ind+1]-'0';
            if(d1==1||(d1==2&&d2<=6))
            twostep=solve(digits,ind+2,dp);
        }
        return dp[ind]= onestep+twostep;
    }
    int numDecodings(string digits) {
        int n=digits.size();
        //first digit can not be zero
    //    if(digits[0]=='0'){
    //        return 0;
    //    }
       vector<int>dp(n+1,-1);
    //    //if there is number other than 1,2 before any zero then zero answer
    //    //there should not be two consecutive zero also
    //    for(int i=1;i<n;i++){
    //        if(digits[i]=='0'){
    //           int prev=digits[i-1]-'0';
    //           if(prev>2||prev==0){
    //               return 0;
    //           }
    //        }
           
    //    }
        return solve(digits,0,dp);
        
    }
};