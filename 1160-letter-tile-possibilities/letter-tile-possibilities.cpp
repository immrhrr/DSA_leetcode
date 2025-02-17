class Solution {
public:
    void solve(string&tiles,unordered_set<string>&st,vector<bool>used,string curr){
        st.insert(curr);
        int n=tiles.size();
        for(int i=0;i<n;i++){
            if(used[i]){
                continue;
            }
            //do
            curr+=tiles[i];
            used[i]=true;
            //explore
            solve(tiles,st,used,curr);
            //backtrack
            curr.pop_back();
            used[i]=false;
        }
        

    }
    int numTilePossibilities(string tiles) {
        unordered_set<string>st;
        int n=tiles.size();
        vector<bool>used(n,false);
        string curr;
        solve(tiles,st,used,curr);
        return st.size()-1;
    }
};