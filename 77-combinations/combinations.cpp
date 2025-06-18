class Solution {
public:
    void solve(int n,int k,vector<vector<int>>&ans,vector<int>arr,int curr){
        if(arr.size()==k){
            ans.push_back(arr);
            return;
        }
        if(curr>n){
            return;
        }
        for(int i=curr;i<=n;i++){
            arr.push_back(i);
            solve(n,k,ans,arr,i+1);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(n,k,ans,arr,1);
        return ans;
    }
};