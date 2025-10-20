class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int n=op.size();
        int ans=0;
        for(int i=0;i<n;i++){
            string temp=op[i];
            if(temp=="++X"||temp=="X++"){
                ans++;
            }
            else{
                ans--;
            }
        }
        return ans;
    }
};