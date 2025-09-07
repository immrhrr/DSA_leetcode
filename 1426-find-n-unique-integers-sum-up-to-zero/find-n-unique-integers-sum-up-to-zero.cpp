class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans;
        if(n%2==1){
            int cnt=1;
            ans.push_back(0);
            int p=1;
            int nn=-1;
            while(cnt<n){
                cnt+=2;
                ans.push_back(p);
                ans.push_back(nn);
                p++;nn--;
            }
            return ans;
        }
        else{
            int cnt=0;
            int p=1;
            int nn=-1;
            while(cnt<n){
                cnt+=2;
                ans.push_back(p);
                ans.push_back(nn);
                p++;nn--;
            }
            return ans;
        }
        return ans;
    }
};