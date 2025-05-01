class Solution {
public:
    vector<int> getRow(int n) {
        n++;
        vector<int>ans(n,1);
        long long temp=1;
        for(int i=1;i<n;i++){
            temp=temp*(n-i);
            temp=temp/i;
            ans[i]=(int)temp;
        }
        return ans;
        
    }
};