class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        if(n%k!=0){
            int rem=n%k;
            for(int i=0;i<(k-rem);i++){
                s+=fill;
            }
        }
        int m=(n+k-1)/k;
        vector<string>ans(m);
        for(int i=0;i<m;i++){
            string temp;
            for(int j=0;j<k;j++){
                int ind=(i*k)+j;
                temp+=s[ind];
            }
            ans[i]=temp;
        }
        return ans;
    }
};