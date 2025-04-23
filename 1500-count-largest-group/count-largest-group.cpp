class Solution {
public:
    int solve(int n){
        int curr=0;
        while(n>0){
            curr+=n%10;
            n=n/10;
        }
        return curr;
    }

    int countLargestGroup(int n) {
        vector<int>temp(37,0);
        int ans=0;
        int maxi=0;
        for(int i=1;i<=n;i++){
            int sum=solve(i);
            temp[sum]++;
           if(temp[sum]==maxi){
            ans++;
           }
           else{
            if(temp[sum]>maxi){
                maxi=temp[sum];
                ans=1;
            }
           }
        }
        return ans;
    }
};