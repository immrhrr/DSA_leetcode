class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int c=1,empty=0;
        for(auto i:flowerbed){
            if(i==1)c=0;
            else{
                c++;
                if(c==3){
                    empty++;
                    c=1;
                }
            }
        }
        if(!flowerbed.back()){
            c++;
            if(c==3)
                empty++;
        }
        return empty>=n;
    }
};