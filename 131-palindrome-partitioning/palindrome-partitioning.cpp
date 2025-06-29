class Solution {
public:
    bool check(string&s1){
        if(s1.size()==1)return true;
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
    void solve(string&s,vector<vector<string>>&ans,vector<string>temp,int ind){
        int n=s.size();
        if(ind>=n){
            ans.push_back(temp);
        }
        for(int i=ind;i<n;i++){
            string curr = s.substr(ind, i - ind + 1); 
            //string curr=s.substr(ind,i+1);
            if(check(curr)){
                temp.push_back(curr);
                solve(s,ans,temp,i+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(s,ans,temp,0);
        return ans;
    }
};