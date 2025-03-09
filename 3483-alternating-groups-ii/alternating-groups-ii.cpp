class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        for(int i=0;i<k-1;i++){
            colors.push_back(colors[i]);
        }
        int n=colors.size();
        int i=0;
        int j=1;
        int ans=0;
        while(j<n){
            if(colors[j]==colors[j-1]){
                i=j;
            }
            else{
                if(j-i+1==k){
                    ans++;
                    i++;
                }
            }
            j++;  
        }
        return ans;
    }
};