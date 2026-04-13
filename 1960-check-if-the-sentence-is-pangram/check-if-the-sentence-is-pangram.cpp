class Solution {
public:
    bool checkIfPangram(string s) {
        int n=s.size();
        vector<bool>flag(26,false);
        int temp=-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            temp=s[i]-'a';
            if(flag[temp]==false){
                flag[temp]=true;
                cnt++;
            }
        }
        return cnt==26;
        
    }
};