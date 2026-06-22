class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        vector<int>arr(26,0);
        for(int i=0;i<n;i++){
            arr[text[i]-'a']++;
        }
        int ans=10000;
        ans=min({ans,arr[0],arr[1],arr[11]/2,arr[14]/2,arr[13]});
        return ans;
        
    }
};
