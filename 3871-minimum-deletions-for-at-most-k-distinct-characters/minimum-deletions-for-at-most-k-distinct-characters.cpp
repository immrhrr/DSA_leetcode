class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int>frq(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            frq[s[i]-'a']++;
        }
        int ans=0;
        sort(frq.begin(),frq.end());
        for(int i=25-k;i>=0;i--){
            ans+=frq[i];
        }
        return ans;
        
    }
};