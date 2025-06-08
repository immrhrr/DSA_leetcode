class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int last=prices[n-1];
        for(int i=n-2;i>=0;i--){
            ans=max(ans,last-prices[i]);
            if(prices[i]>last){
                last=prices[i];
            }
        }
        return ans;
        
    }
};