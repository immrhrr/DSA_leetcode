class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        
        vector<string>ans;
        unordered_set<string>st(supplies.begin(),supplies.end());
        int cnt=n;
        while(cnt--){
             for(int i=0;i<n;i++){
            bool flag=true;
            if(st.find(recipes[i])!=st.end())
            continue;
            for(int j=0;j<ingredients[i].size();j++){
                if(st.find(ingredients[i][j])==st.end()){
                    flag=false;
                    break;
                }

            }
            if(flag){
                ans.push_back(recipes[i]);
                st.insert(recipes[i]);
            }
        }

        }
       
        return ans;
    }
};