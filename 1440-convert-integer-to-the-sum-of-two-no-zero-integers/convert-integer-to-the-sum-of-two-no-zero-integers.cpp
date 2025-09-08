class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<bool>temp(1e4,true);
        for(int i=10;i<1e4;i++){
            int curr=i;
            while(curr>0){
                int d=curr%10;
                if(d==0){
                    temp[i]=false;
                    break;
                }
                curr=curr/10;
            }
        }
        for(int i=1;i<n;i++){
            int j=n-i;
            if(temp[i]&&temp[j])
            return{i,j};
        }
        return {};
    }
};