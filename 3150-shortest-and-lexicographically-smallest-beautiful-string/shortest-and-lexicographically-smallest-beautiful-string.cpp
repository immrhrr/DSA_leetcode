class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int i=0;
        int j=0;
        string res="";
        int n=s.size();
        int ones=0;
        while(j<n){
            if(s[j]=='1'){
                ones++;
            }
            while(ones>k||s[i]=='0'){
                if(s[i]=='1'){
                    ones--;
                }
                i++;
            }
            if(ones==k){
                string temp=s.substr(i,j-i+1);
                if(res.empty()||res.size()>j-i+1||(temp.size()==res.size()&&temp<res)){
                    res=temp;
                }
            }
            j++;
        }
        return res;
    }
};