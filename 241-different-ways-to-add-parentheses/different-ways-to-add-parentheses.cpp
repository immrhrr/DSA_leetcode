class Solution {
public:
   vector<int>solve(string exp){
    vector<int>ans;
    for(int i=0;i<exp.size();i++){
        if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*'){
            vector<int>left=solve(exp.substr(0,i));
            vector<int>right=solve(exp.substr(i+1));
            for(int&l:left){
                for(int&r:right){
                    if(exp[i]=='+'){
                        ans.push_back(l+r);
                    }
                    else if(exp[i]=='-'){
                        ans.push_back(l-r);
                    }
                    else if(exp[i]=='*'){
                        ans.push_back(l*r);
                    }
                }
            }
        }
    }
    if(ans.empty()){
        ans.push_back(stoi(exp));
    }
    return ans;
   }
    vector<int> diffWaysToCompute(string exp) {
        return solve(exp);
        
    }
};