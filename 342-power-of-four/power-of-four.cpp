class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)return false;
        vector<int>arr;
        while(n>0){
            arr.push_back(n%4);
            n=n/4;
        }
        reverse(arr.begin(),arr.end());
        if(arr[0]!=1)return false;
        for(int i=1;i<arr.size();i++){
            if(arr[i]!=0)return false;

        }
        return true;
    }
};