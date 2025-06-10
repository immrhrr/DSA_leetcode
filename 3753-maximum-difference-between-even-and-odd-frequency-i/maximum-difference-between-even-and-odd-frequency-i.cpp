class Solution {
public:
    int maxDifference(string s) {
        //odd - even ka maxi
        int n=s.size();
        vector<int>arr(26);
        for(int i=0;i<n;i++){
            arr[s[i]-'a']++;
        }
       int even_min=INT_MAX;
       int odd_max=INT_MIN;
       for(int i=0;i<26;i++){
        if(arr[i]!=0&&arr[i]%2==0){
            even_min=min(even_min,arr[i]);
        }
        else{
            odd_max=max(odd_max,arr[i]);
        }
       }
       return odd_max-even_min;
        
        
    }
};