class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.size();
        vector<string>ans;
        unordered_set<string>vis;
        string temp;
        for(int i=0;i<n;i++){
            temp+=s[i];
            //ye wala string abhi set mein nhi hai
            if(vis.find(temp)==vis.end()){
                ans.push_back(temp);
                vis.insert(temp);
                temp="";
            }
        }
        return ans;
    }
};