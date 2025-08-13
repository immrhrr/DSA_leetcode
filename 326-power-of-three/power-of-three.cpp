class Solution {
public:
    void solve(vector<int>&arr,int n){
        while(n>0){
            int t=n%3;
            arr.push_back(t);
            n=n/3;
        }
        return;
    }
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        vector<int>arr;
        solve(arr,n);
        reverse(arr.begin(),arr.end());
        if(arr[0]!=1)return false;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=0)return false;
        }
        return true;
        
    }
};