class Solution {
public:
    string clearStars(string s) {
        int n=s.size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                auto it=pq.top();
                pq.pop();
                s[it.second]='*';
            }
            else{
                int temp=s[i]-'a';
                pq.push({-1*temp,i});
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                ans+=s[i];
            }
        }
        return ans;
    }
};