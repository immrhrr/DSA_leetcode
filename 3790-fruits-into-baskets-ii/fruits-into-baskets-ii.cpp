class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int>vis(n,-1);
        int cnt=0;
        for(int i=0;i<n;i++){
            int need=fruits[i];
            for(int j=0;j<n;j++){
                if(vis[j]==1){
                    continue;
                }
                int available=baskets[j];
                if(need<=available){
                    vis[j]=1;
                    cnt++;
                    break;
                }
            }
        }
        
        
        return n-cnt;
    }
};