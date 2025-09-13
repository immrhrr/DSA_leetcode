class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>arr(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
        int v=0;
        int c=0;
        for(int i=0;i<26;i++){
            if(i==0||i==4||i==8||i==14||i==20){
                v=max(v,arr[i]);
            }
            else{
                c=max(c,arr[i]);
            }
        }
        
        return v+c;
    }
};