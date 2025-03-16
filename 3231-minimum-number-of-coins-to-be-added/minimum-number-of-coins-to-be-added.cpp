class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        int cum_sum=0;
        int i=0;
        int ans=0;
        while(cum_sum<target){
            if(i<n&&coins[i]<=cum_sum+1){
                cum_sum+=coins[i];
                i++;
            }
            else{
                ans++;
                cum_sum+=(cum_sum+1);
                
            }
        }
        return ans;
    }
};