class Solution {
public:
    int maxProduct(int n) {
        vector<int>arr;
        while(n>0){
            int d=n%10;
            arr.push_back(d);
            n=n/10;
        }
        int ans=0;
        sort(arr.rbegin(),arr.rend());
        ans=arr[0]*arr[1];
        return ans;
    }
};