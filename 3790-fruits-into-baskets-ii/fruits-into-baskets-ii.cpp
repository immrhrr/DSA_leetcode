class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        int filled=0;
        for(int i=0;i<n;i++){
            int curr=fruits[i];
            for(int j=0;j<n;j++){
                if(baskets[j]>=curr){
                    baskets[j]=0;
                    filled++;
                    break;
                }
            }
        }
        return n-filled;
        
    }
};