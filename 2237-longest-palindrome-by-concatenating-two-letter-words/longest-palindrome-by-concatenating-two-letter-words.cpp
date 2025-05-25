class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        int ans=0;
        unordered_map<string,int>mp;
        string s,ss;
        for(int i=0;i<n;i++){
            //sabse pehle map mein iska reverse check kro
            s=words[i];
            ss=s;
            reverse(ss.begin(),ss.end());
            if(mp.find(ss)!=mp.end()){
                ans+=4;
                mp[ss]--;
                if(mp[ss]==0){
                    mp.erase(ss);
                }
            }else
            mp[s]++;
        }
        int cnt=0;
        for(auto it:mp){
            s=it.first;
            cnt=it.second;
            if(s[0]==s[1]){
                ans+=2;
                break;
            }
        }
        return ans;
        
    }
};