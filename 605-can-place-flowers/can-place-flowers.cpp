class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int n) {
        int m=arr.size();
        int temp=1;
        int empty=0;
        for(int i=0;i<m;i++){
            if(arr[i]==1){
                temp=0;
            }
            else{
                temp++;
                if(temp==3){
                    empty++;
                    temp=1;
                }
            }
        }
        if(arr[m-1]==0){
            temp++;
            if(temp==3){
                empty++;
            }
        }
        return empty>=n;
        
        
    }
};