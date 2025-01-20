class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        unordered_map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]=i;
        }
        vector<int>row(n,INT_MIN);
        vector<int>col(m,INT_MIN);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i]=max(row[i],mp[mat[i][j]]);
                col[j]=max(col[j],mp[mat[i][j]]);
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            ans=min(ans,row[i]);
        }
        for(int j=0;j<m;j++){
            ans=min(ans,col[j]);
        }
        return ans;

    }
};