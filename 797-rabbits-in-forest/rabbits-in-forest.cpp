class Solution {
public:
    int numRabbits(vector<int>& ans) {
        int n=ans.size();
        int cnt=0;
        sort(ans.begin(),ans.end());
        int i=0;
        while(i<n){
            int curr_val=ans[i];
            int n=ans[i];
            cnt+=curr_val+1;
           while(n>0&&ans[i+1]==curr_val){
            i++;
            n--;
           }
           i++;
        }
        return cnt;   
    }
};