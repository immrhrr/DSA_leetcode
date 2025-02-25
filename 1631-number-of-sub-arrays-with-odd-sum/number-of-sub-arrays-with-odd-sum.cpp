class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
    int n=arr.size();
    long long sum=0;
    long long cnt=0;
    int even=1;
    int odd=0;
    int mod=1e9+7;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        //even
        if(sum%2==0){
            cnt+=odd;
            even++;

        }
        //odd
        else{
            cnt+=even;
            odd++;

        }
    }
    cnt=cnt%mod;
    int ans=cnt;
    return ans;
        
    }
};