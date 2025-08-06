class Solution {
public:
    bool check(vector<int>&frq){
        for(int i=0;i<26;i++){
            if(frq[i]!=0)return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<int>frq(26,0);
        for(int i=0;i<m;i++){
            frq[p[i]-'a']++;
        }
        vector<int>ans;
        int i=0;
        int j=0;
        while(j<n){
            frq[s[j]-'a']--;
            if(m==j-i+1){
                if(check(frq)){
                    ans.push_back(i);
                }
                frq[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};