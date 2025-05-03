class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        //check on the top from 1 to 6
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(tops[j]==i){
                    continue;
                }
                if(bottoms[j]==i){
                    temp++;
                }
                if(tops[j]!=i&&bottoms[j]!=i){
                    temp=INT_MAX;
                    break;
                }
                
            }
            ans=min(ans,temp);
        }
        //check on the bottom from 1 to 6
        for(int i=1;i<=6;i++){
            int temp=0;
            for(int j=0;j<n;j++){
                if(bottoms[j]==i){
                    continue;
                }
                if(tops[j]==i){
                    temp++;
                }
                if(tops[j]!=i&&bottoms[j]!=i){
                    temp=INT_MAX;
                    break;
                }
                
            }
            ans=min(ans,temp);
        }
        if(ans>1e5)return -1;
        return ans;
        //take minimum and return
    }
};