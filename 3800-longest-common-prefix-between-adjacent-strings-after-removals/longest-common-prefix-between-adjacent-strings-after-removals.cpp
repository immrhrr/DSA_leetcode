class Solution {
public:
    int find(string &s1,string&s2){
        int n1=s1.size();
        int n2=s2.size();
        int n=min(n1,n2);
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                return i;
            }
        }
        return n;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int>ans(n,0);
        vector<int>left(n,0);
        for(int i=2;i<n;i++){
            int curr=find(words[i-1],words[i-2]);
            left[i]=max(left[i-1],curr);
        }
        vector<int>right(n,0);
        for(int i=n-3;i>=0;i--){
            int curr=find(words[i+1],words[i+2]);
            right[i]=max(right[i+1],curr);
        }
        for(int i=0;i<n;i++){
            ans[i]=max(left[i],right[i]);
            int curr=0;
            if(i-1>=0&&i+1<n){
            curr=find(words[i-1],words[i+1]);
            }
            ans[i]=max(ans[i],curr);
        }
        return ans;
    }
};