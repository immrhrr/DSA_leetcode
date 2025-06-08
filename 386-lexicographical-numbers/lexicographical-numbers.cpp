class Solution {
public:
    void dfs(vector<int>&ans,int &curr,int &n){
        if(curr>n)return;
        ans.push_back(curr);
        for(int i=0;i<=9;i++){
            int next=curr*10+i;
            if(next>n)return;
            dfs(ans,next,n);
        }
        return;
    }
    vector<int> lexicalOrder(int n) {
        vector<int>ans;
        for(int start=1;start<=9;start++){
            dfs(ans,start,n);
        }
        return ans;
        
    }
};