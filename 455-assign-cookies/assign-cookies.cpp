class Solution {
public:
    int findContentChildren(vector<int>& players, vector<int>& trainers) {
          int ans=0;
        int n=players.size();
        int m=trainers.size();
        int i=0;int j=0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<n&&j<m){
            if(players[i]<=trainers[j]){
                i++;
                j++;
                ans++;
            }
            else if(players[i]>trainers[j]){
                j++;
            }
        }
        return ans;
    }
};