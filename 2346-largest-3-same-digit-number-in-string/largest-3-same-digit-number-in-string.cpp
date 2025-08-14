class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        vector<int>arr(10,0);
        for(int i=2;i<n;i++){
            if(num[i]==num[i-1]&&num[i]==num[i-2]){
                arr[num[i]-'0']=1;
            }
        }
        string ans="";
        for(int i=9;i>0;i--){
            if(arr[i]==1){
             ans=to_string(i*111);
             return ans;
            }
        }
        if(arr[0]==1){
            return "000";
        }
        return ans;
    }
};