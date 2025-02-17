class Solution {
public:
    void solve(vector<int>&frq,int &cnt){
        cnt++;
        for(int i=0;i<26;i++){
            if(frq[i]==0){
                continue;
            }
            //do
            frq[i]--;
            //explore
            solve(frq,cnt);
            //backtrack
            frq[i]++;
        }
        return;
    }
    int numTilePossibilities(string tiles) {
        int n=tiles.size();
        vector<int>frq(26,0);
        for(int i=0;i<n;i++){
            int ind=tiles[i]-'A';
            frq[ind]++;
        }
        int cnt=0;
        solve(frq,cnt);
        return cnt-1;
    }
};