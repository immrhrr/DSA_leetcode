class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int>mp;
        int n=dominoes.size();
        for(int i=0;i<n;i++){
            int a=max(dominoes[i][0],dominoes[i][1]);
            int b=min(dominoes[i][0],dominoes[i][1]);
            mp[10*a+b]++;
        }
        int ans=0;
        for(auto it:mp){
            int x=it.second;
            ans+=((x)*(x-1))/2;
        }
        return ans;
        
    }
};