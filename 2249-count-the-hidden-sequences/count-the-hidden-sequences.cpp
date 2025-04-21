class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int u) {
        int curr=100;
        int mini=100;
        int maxi=100;
        for(int i=0;i<diff.size();i++){
            curr=curr+diff[i];
            mini=min(mini,curr);
            maxi=max(maxi,curr);
            if((u-maxi)-(l-mini)+1<=0)return 0;
        }
        return (u-maxi)-(l-mini)+1;

        
    }
};