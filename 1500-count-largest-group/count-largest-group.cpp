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
        for(int i=1;i<=n;i++){
            int sum=solve(i);
            temp[sum]++;
        }
        sort(temp.rbegin(),temp.rend());
        int ans=1;
        for(int i=1;i<=36;i++){
            if(temp[i]==temp[0]){
                ans++;
            }
            else{
                break;
            }
        }
        return ans;
    }
};