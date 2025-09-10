class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& lang, vector<vector<int>>& f) {
        unordered_set<int>st;
        int m=f.size();
        for(int ind=0;ind<m;ind++){
            int f1=f[ind][0]-1;
            int f2=f[ind][1]-1;
            int n1=lang[f1].size();
            int n2=lang[f2].size();
            bool is_sad=true;
            for(int i=0;i<n1;i++){
                for(int j=0;j<n2;j++){
                    if(lang[f1][i]==lang[f2][j]){
                        is_sad=false;
                        break;
                    }
                }
                if(is_sad==false){
                    break;
                }
            }
            if(is_sad){
                st.insert(f1);
                st.insert(f2);
            }
        }
        //most known lang among all the sad people is that we have to find
        vector<int>l(n+1,0);
        int maxi=0;
        for(int people:st){
            for(int i=0;i<lang[people].size();i++){
                l[lang[people][i]]++;
                maxi=max(maxi,l[lang[people][i]]);
            }
        }
        return st.size()-maxi;
        
    }
};