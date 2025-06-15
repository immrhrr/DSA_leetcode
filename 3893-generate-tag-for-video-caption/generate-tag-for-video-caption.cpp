class Solution {
public:
    string generateTag(string caption) {
        int n=caption.size();
        string ans;
        ans+='#';
        int cnt=1;
        bool uppercase=false;
        for(int i=0;i<n;i++){
            if(cnt==100){
                return ans;
            }
            if(caption[i]==' '){
                uppercase=true;
                continue;
            }
            if(uppercase){
                ans+=toupper(caption[i]);
                cnt++;
                uppercase=false;
                continue;
            }
            else{
                ans+=tolower(caption[i]);
                cnt++;
            }
        }
        ans[1]=tolower(ans[1]);
        return ans;
        
    }
};